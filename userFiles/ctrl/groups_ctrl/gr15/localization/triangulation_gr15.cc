#include "triangulation_gr15.h"
#include "useful_gr15.h"
#include "init_pos_gr15.h"
#include <math.h>

NAMESPACE_INIT(ctrlGr15);

/*! \brief set the fixed beacons positions, depending on the team
 * 
 * \param[in] team_id ID of the team ('TEAM_A' or 'TEAM_B')
 * \param[out] x_beac_1 first beacon x position [m]
 * \param[out] y_beac_1 first beacon y position [m]
 * \param[out] x_beac_2 second beacon x position [m]
 * \param[out] y_beac_2 second beacon y position [m]
 * \param[out] x_beac_3 third beacon x position [m]
 * \param[out] y_beac_3 third beacon y position [m]
 *
 * This function can be adapted, depending on the map.
 */
void fixed_beacon_positions(int team_id, double *x_beac_1, double *y_beac_1, double *theta_beac_1,
	double *x_beac_2, double *y_beac_2, double *theta_beac_2, double *x_beac_3, double *y_beac_3, double *theta_beac_3)
{
	switch (team_id)
	{
		case TEAM_A: //start at -180°
			*x_beac_1 = 0.0;
			*y_beac_1 = -1.562;
			*theta_beac_1 = -M_PI/2;

			*x_beac_2 = 1.062;
			*y_beac_2 = 1.562;
			*theta_beac_2 = M_PI/4;

			*x_beac_3 = -1.062;
			*y_beac_3 = 1.562;
			*theta_beac_3 = 3*M_PI/4;
			break;

		case TEAM_B: //start at -180°
			*x_beac_1 = -1.062;
			*y_beac_1 = -1.562;
			*theta_beac_1 = -3*M_PI/4;

			*x_beac_2 = 1.062;
			*y_beac_2 = -1.562;
			*theta_beac_2 = -M_PI/4;

			*x_beac_3 = 0.0;
			*y_beac_3 = 1.562;
			*theta_beac_3 = M_PI/2;
			break;
	
		default:
			printf("Error unknown team ID (%d) !\n", team_id);
			exit(EXIT_FAILURE);
	}
}

/*! \brief get the index of the best angle prediction
 * 
 * \param[in] alpha_predicted angle to reach [rad]
 * \param[in] alpha_a angle computed for A [rad]
 * \param[in] alpha_b angle computed for B [rad]
 * \param[in] alpha_c angle computed for C [rad]
 * \return best index (0, 1, or 2)
 */
int index_predicted(double alpha_predicted, double alpha_a, double alpha_b, double alpha_c)
{
	double pred_err_a, pred_err_b, pred_err_c;

	pred_err_a = fabs(limit_angle(alpha_a - alpha_predicted));
	pred_err_b = fabs(limit_angle(alpha_b - alpha_predicted));
	pred_err_c = fabs(limit_angle(alpha_c - alpha_predicted));

	return (pred_err_a < pred_err_b) ? ((pred_err_a < pred_err_c) ? 0 : 2) : ((pred_err_b < pred_err_c) ? 1 : 2);
}


/*! \brief triangulation main algorithm
 * 
 * \param[in] cvs controller main structure
 *
 * computation found here: http://www.telecom.ulg.ac.be/triangulation/
 */
void triangulation(CtrlStruct *cvs)
{
	// variables declaration
	RobotPosition *pos_tri, *rob_pos;
	CtrlIn *inputs;

	int alpha_1_index, alpha_2_index, alpha_3_index;
	int rise_index_1, rise_index_2, rise_index_3;
	int fall_index_1, fall_index_2, fall_index_3;
	double order[6];

	double alpha_a, alpha_b, alpha_c;
	double alpha_1, alpha_2, alpha_3;
	double alpha_1_predicted, alpha_2_predicted, alpha_3_predicted;
	double x_beac_1, y_beac_1, x_beac_2, y_beac_2, x_beac_3, y_beac_3;
	double theta_beac_1, theta_beac_2, theta_beac_3;

	double x_beac_1_p, y_beac_1_p, x_beac_3_p, y_beac_3_p;
	double cot_12, cot_23, cot_31;
	double x_beac_12_p, y_beac_12_p, x_beac_23_p, y_beac_23_p, x_beac_31_p, y_beac_31_p;
	double k_31_p, D;

	// variables initialization
	pos_tri = cvs->triang_pos;
	rob_pos = cvs->rob_pos;
	inputs  = cvs->inputs;

	// safety
	if ((inputs->rising_index_fixed < 0) || (inputs->falling_index_fixed < 0))
	{
		return;
	}

	// known positions of the beacons
	fixed_beacon_positions(cvs->team_id, &x_beac_1, &y_beac_1, &theta_beac_1, &x_beac_2, &y_beac_2, &theta_beac_2,
		 &x_beac_3, &y_beac_3, &theta_beac_3);	

	// indexes for the angles detection
	rise_index_1 = inputs->rising_index_fixed;
	rise_index_2 = (rise_index_1 - 1 < 0) ? NB_STORE_EDGE-1 : rise_index_1 - 1;
	rise_index_3 = (rise_index_2 - 1 < 0) ? NB_STORE_EDGE-1 : rise_index_2 - 1;

	fall_index_1 = inputs->falling_index_fixed;
	fall_index_2 = (fall_index_1 - 1 < 0) ? NB_STORE_EDGE-1 : fall_index_1 - 1;
	fall_index_3 = (fall_index_2 - 1 < 0) ? NB_STORE_EDGE-1 : fall_index_2 - 1;

	// ordering the index of rising and falling
	order[0] = delimit_angle(inputs->last_rising_fixed[rise_index_1]);
	order[2] = delimit_angle(inputs->last_rising_fixed[rise_index_2]);
	order[4] = delimit_angle(inputs->last_rising_fixed[rise_index_3]);

	if (fabs(delimit_angle(inputs->last_rising_fixed[rise_index_1])-delimit_angle(inputs->last_falling_fixed[fall_index_1]))<fabs(delimit_angle(inputs->last_rising_fixed[rise_index_1])-delimit_angle(inputs->last_falling_fixed[fall_index_2])) 
		&& fabs(delimit_angle(inputs->last_rising_fixed[rise_index_1])-delimit_angle(inputs->last_falling_fixed[fall_index_1]))<fabs(delimit_angle(inputs->last_rising_fixed[rise_index_1])-delimit_angle(inputs->last_falling_fixed[fall_index_3])))
	{
		order[1] = delimit_angle(inputs->last_falling_fixed[fall_index_1]);

		if (fabs(delimit_angle(inputs->last_rising_fixed[rise_index_2])-delimit_angle(inputs->last_falling_fixed[fall_index_2]))<fabs(delimit_angle(inputs->last_rising_fixed[rise_index_2])-delimit_angle(inputs->last_falling_fixed[fall_index_3])))
		{
			order[3] = delimit_angle(inputs->last_falling_fixed[fall_index_2]);
			order[5] = delimit_angle(inputs->last_falling_fixed[fall_index_3]);
		}
		else 
		{
			order[3] = delimit_angle(inputs->last_falling_fixed[fall_index_3]);
			order[5] = delimit_angle(inputs->last_falling_fixed[fall_index_2]);
		}
	}
	if (fabs(delimit_angle(delimit_angle(inputs->last_rising_fixed[rise_index_1]))-delimit_angle(inputs->last_falling_fixed[fall_index_2]))<fabs(delimit_angle(delimit_angle(inputs->last_rising_fixed[rise_index_1]))-delimit_angle(inputs->last_falling_fixed[fall_index_1])) 
		&& fabs(delimit_angle(delimit_angle(inputs->last_rising_fixed[rise_index_1]))-delimit_angle(inputs->last_falling_fixed[fall_index_2]))<fabs(delimit_angle(delimit_angle(inputs->last_rising_fixed[rise_index_1]))-delimit_angle(inputs->last_falling_fixed[fall_index_3])))
	{
		order[1] = delimit_angle(inputs->last_falling_fixed[fall_index_2]);

		if (fabs(delimit_angle(inputs->last_rising_fixed[rise_index_2])-delimit_angle(inputs->last_falling_fixed[fall_index_1]))<fabs(delimit_angle(inputs->last_rising_fixed[rise_index_2])-delimit_angle(inputs->last_falling_fixed[fall_index_3])))
		{
			order[3] = delimit_angle(inputs->last_falling_fixed[fall_index_1]);
			order[5] = delimit_angle(inputs->last_falling_fixed[fall_index_3]);
		}
		else 
		{
			order[3] = delimit_angle(inputs->last_falling_fixed[fall_index_3]);
			order[5] = delimit_angle(inputs->last_falling_fixed[fall_index_1]);
		}
	}
	if (fabs(delimit_angle(delimit_angle(inputs->last_rising_fixed[rise_index_1]))-delimit_angle(inputs->last_falling_fixed[fall_index_3]))<fabs(delimit_angle(delimit_angle(inputs->last_rising_fixed[rise_index_1]))-delimit_angle(inputs->last_falling_fixed[fall_index_1])) 
		&& fabs(delimit_angle(delimit_angle(inputs->last_rising_fixed[rise_index_1]))-delimit_angle(inputs->last_falling_fixed[fall_index_3]))<fabs(delimit_angle(delimit_angle(inputs->last_rising_fixed[rise_index_1]))-delimit_angle(inputs->last_falling_fixed[fall_index_2])))
	{
		order[1] = delimit_angle(inputs->last_falling_fixed[fall_index_3]);

		if (fabs(delimit_angle(inputs->last_rising_fixed[rise_index_2])-delimit_angle(inputs->last_falling_fixed[fall_index_1]))<fabs(delimit_angle(inputs->last_rising_fixed[rise_index_2])-delimit_angle(inputs->last_falling_fixed[fall_index_2])))
		{
			order[3] = delimit_angle(inputs->last_falling_fixed[fall_index_1]);
			order[5] = delimit_angle(inputs->last_falling_fixed[fall_index_2]);
		}
		else 
		{
			order[3] = delimit_angle(inputs->last_falling_fixed[fall_index_2]);
			order[5] = delimit_angle(inputs->last_falling_fixed[fall_index_1]);
		}
	}
	
	// beacons angles measured with the laser
	alpha_a = limit_angle((order[1]+order[0])/2);
	alpha_b = limit_angle((order[3]+order[2])/2);
	alpha_c = limit_angle((order[5]+order[4])/2);

	// beacons angles predicted thanks to odometry measurements (to compute)
	alpha_1_predicted = limit_angle(theta_beac_1 - rob_pos->theta);
	alpha_2_predicted = limit_angle(theta_beac_2 - rob_pos->theta);
	alpha_3_predicted = limit_angle(theta_beac_3 - rob_pos->theta);

	// indexes of each beacon
	alpha_1_index = index_predicted(alpha_1_predicted, alpha_a, alpha_b, alpha_c);
	alpha_2_index = index_predicted(alpha_2_predicted, alpha_a, alpha_b, alpha_c);
	alpha_3_index = index_predicted(alpha_3_predicted, alpha_a, alpha_b, alpha_c);

	// safety
	if ((alpha_1_index == alpha_2_index) || (alpha_1_index == alpha_3_index) || (alpha_2_index == alpha_3_index))
	{
		return;
	}

	// angle of the first beacon
	switch (alpha_1_index)
	{
		case 0: alpha_1 = alpha_a; break;
		case 1: alpha_1 = alpha_b; break;
		case 2: alpha_1 = alpha_c; break;
	
		default:
			printf("Error: unknown index %d !\n", alpha_1_index);
			exit(EXIT_FAILURE);
	}

	// angle of the second beacon
	switch (alpha_2_index)
	{
		case 0: alpha_2 = alpha_a; break;
		case 1: alpha_2 = alpha_b; break;
		case 2: alpha_2 = alpha_c; break;
	
		default:
			printf("Error: unknown index %d !\n", alpha_2_index);
			exit(EXIT_FAILURE);
	}

	// angle of the third beacon
	switch (alpha_3_index)
	{
		case 0: alpha_3 = alpha_a; break;
		case 1: alpha_3 = alpha_b; break;
		case 2: alpha_3 = alpha_c; break;
	
		default:
			printf("Error: unknown index %d !\n", alpha_3_index);
			exit(EXIT_FAILURE);
	}
	

	// ----- triangulation computation start ----- //
	// beacon angle start is -180° and end is 180°

	//modified beacon angles
	x_beac_1_p = x_beac_1 - x_beac_2;
	y_beac_1_p = y_beac_1 - y_beac_2;
	x_beac_3_p = x_beac_3 - x_beac_2;
	y_beac_3_p = y_beac_3 - y_beac_2;

	//cotans
	cot_12 = cos(alpha_2_index-alpha_1_index)/sin(alpha_2_index-alpha_1_index);
	cot_23 = cos(alpha_3_index-alpha_2_index)/sin(alpha_3_index-alpha_2_index);
	cot_31 = (1-cot_12*cot_23)/(cot_12+cot_23);

	//modified circle center coordinates
	x_beac_12_p = x_beac_1_p + cot_12*y_beac_1_p;
	y_beac_12_p = y_beac_1_p - cot_12*x_beac_1_p;
	x_beac_23_p = x_beac_3_p - cot_23*y_beac_3_p;
	y_beac_23_p = y_beac_3_p + cot_23*x_beac_3_p;
	x_beac_31_p = (x_beac_3_p+x_beac_1_p)+cot_31*(y_beac_3_p-y_beac_1_p);
	y_beac_31_p = (y_beac_3_p+y_beac_1_p)-cot_31*(x_beac_3_p-x_beac_1_p);

	//compute k and D
	k_31_p = x_beac_1_p*x_beac_3_p + y_beac_1_p*y_beac_3_p + 
		cot_31*(x_beac_1_p*y_beac_3_p - x_beac_3_p*y_beac_1_p);
	D = (x_beac_12_p - x_beac_23_p)*(y_beac_23_p - y_beac_31_p) -
		(y_beac_12_p - y_beac_23_p)*(x_beac_23_p - x_beac_31_p);
	if (D == 0)
	{
		printf("Error: D = 0 !\n");
		exit(EXIT_FAILURE);
	}

	// robot position
	pos_tri->x = x_beac_2 + (k_31_p*(y_beac_12_p - y_beac_23_p))/D;
	pos_tri->y = y_beac_2 + (k_31_p*(x_beac_23_p - x_beac_12_p))/D;

	// robot orientation (mean between the 3 angles measured)
	pos_tri->theta = limit_angle(((theta_beac_1 - alpha_1_index)+(theta_beac_2 - alpha_2_index)+(theta_beac_3 - alpha_3_index))/3);

	//printf("index of rising : %i, %i, %i \n", rise_index_1, rise_index_2, rise_index_3);
	//printf("rising mesurés : 1 = %f, 2 = %f, 3 = %f\n", order[0], order[2], order[4]);
	//printf("index of falling : %i, %i, %i \n", fall_index_1, fall_index_2, fall_index_3);
	//printf("falling mesurés : 1 = %f, 2 = %f, 3 = %f\n", order[1], order[3], order[5]);
	//printf("angles mesurés : a = %f, 2 = %f, 3 = %f\n", alpha_a, alpha_b, alpha_c);
	printf("triangulation : x = %f, y = %f, theta = %f\n", pos_tri->x, pos_tri->y, pos_tri->theta);
	printf("odometry : x = %f, y = %f, theta = %f\n", rob_pos->x, rob_pos->y, rob_pos->theta);

	// ----- triangulation computation end ----- //
}

NAMESPACE_CLOSE();
