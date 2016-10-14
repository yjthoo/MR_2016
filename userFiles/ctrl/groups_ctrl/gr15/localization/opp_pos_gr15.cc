#include "opp_pos_gr15.h"
#include "init_pos_gr15.h"
#include "useful_gr15.h"
#include <math.h>

NAMESPACE_INIT(ctrlGr15);

/*! \brief compute the opponents position using the tower
 * 
 * \param[in,out] cvs controller main structure
 */
void opponents_tower(CtrlStruct *cvs)
{
	// variables declaration
	int nb_opp;
	int rise_index_1, rise_index_2, fall_index_1, fall_index_2;
    int i;

	double delta_t;
	double rise_1, rise_2, fall_1, fall_2;

	CtrlIn *inputs;
	RobotPosition *rob_pos;
	OpponentsPosition *opp_pos;

	// variables initialization
	inputs  = cvs->inputs;
	rob_pos = cvs->rob_pos;
	opp_pos = cvs->opp_pos;

	nb_opp = opp_pos->nb_opp;

	// no opponent
	if (!nb_opp)
	{
		return;
	}

	// safety
	if (nb_opp < 0 || nb_opp > 2)
	{
		printf("Error: number of opponents cannot be %d!\n", nb_opp);
		exit(EXIT_FAILURE);
	}

	// low pass filter time increment ('delta_t' is the last argument of the 'first_order_filter' function)
	delta_t = inputs->t - opp_pos->last_t;
	opp_pos->last_t = inputs->t;

	// indexes
	rise_index_1 = inputs->rising_index;
	fall_index_1 = inputs->falling_index;

	// rise and fall angles of the first opponent
	rise_1 = inputs->last_rising[rise_index_1];
	fall_1 = inputs->last_falling[fall_index_1];

	// rise and fall angles of the second opponent
	if (nb_opp == 2)
	{
		rise_index_2 = (rise_index_1-1 < 0) ? NB_STORE_EDGE-1 : rise_index_1-1;
		fall_index_2 = (fall_index_1-1 < 0) ? NB_STORE_EDGE-1 : fall_index_1-1;

		rise_2 = inputs->last_rising[rise_index_2];
		fall_2 = inputs->last_falling[fall_index_2];
	}

	// ----- opponents position computation start ----- //
    
    for(i=0; i<nb_opp; i++)
    {
		if (i == 0)
		{
			single_opp_tower(rise_1, fall_1, rob_pos->x, rob_pos->y, rob_pos->theta, opp_pos[i].x, opp_pos[i].y, delta_t); //to detect first robot
		}

		if (i == 1)
		{
			single_opp_tower(rise_2, fall_2, rob_pos->x, rob_pos->y, rob_pos->theta, opp_pos[i].x, opp_pos[i].y, delta_t); //to detect second robot

		}
    } 

	/*if(inputs->t < -14)
	{
		printf("rob theta initial: %f\n", rob_pos->theta);
	}

	if (inputs->t > -10)
	{
		printf("rob theta: %f\n", rob_pos->theta);
	}*/
	

	// ----- opponents position computation end ----- //
}

/*! \brief compute a single opponent position
 * 
 * \param[in] last_rise last rise relative angle [rad]
 * \param[in] last_fall last fall relative angle [rad]
 * \param[in] rob_x robot x position [m]
 * \param[in] rob_y robot y position [m]
 * \param[in] rob_theta robot orientation [rad]
 * \param[out] new_x_opp new known x opponent position
 * \param[out] new_y_opp new known y opponent position
 * \return 1 if computation successful, 0 otherwise
 */
int single_opp_tower(double last_rise, double last_fall, double rob_x, double rob_y, double rob_theta, double *new_x_opp, double *new_y_opp, double delta_t)
{   
	double delta_theta= 0.0;

	if (last_fall - last_rise < 0)
	{
		delta_theta = 2 * M_PI + last_fall - last_rise;
	}
	else
	{
		delta_theta = last_fall - last_rise;
	}
    
	double distance_to_rob = fabs(0.04/tan(delta_theta/2));    // distance from the center of our beacon to the opponent's beacon
    double distance_to_rob_x = distance_to_rob * cos(last_fall-delta_theta/2+rob_theta);
    double distance_to_rob_y = distance_to_rob * sin(last_fall-delta_theta/2+rob_theta);
    
   // *new_x_opp = rob_x + distance_to_rob_x;
   // *new_y_opp = rob_y + distance_to_rob_y;

	//printf("old: %f %f\n", rob_x + distance_to_rob_x, rob_y + distance_to_rob_y);

	*new_x_opp = first_order_filter(*new_x_opp, rob_x + distance_to_rob_x, 0.3, delta_t);
	*new_y_opp = first_order_filter(*new_y_opp, rob_y + distance_to_rob_y, 0.3, delta_t);

	//printf("delta t: %f\n", delta_t); used in the filter

	//printf("filter: %f %f\n", *new_x_opp, *new_y_opp);

	return 1;
}

/*! \brief check if there is an opponent in front of the robot
 * 
 * \param[in] cvs controller main structure
 * \return 1 if opponent robot in front of the current robot
 */
int check_opp_front(CtrlStruct *cvs)
{
	// variables declaration
	int i, nb_opp;

	OpponentsPosition *opp_pos;
	RobotPosition *rob_pos;

	// variables initialization
	rob_pos = cvs->rob_pos;
	opp_pos = cvs->opp_pos;
	nb_opp = opp_pos->nb_opp;

	// no opponent
	if (!nb_opp)
	{
		return 0;
	}

	// safety
	if (nb_opp < 0 || nb_opp > 2)
	{
		printf("Error: number of opponents cannot be %d!\n", nb_opp);
		exit(EXIT_FAILURE);
	}

	for(i=0; i<nb_opp; i++)
	{
		// ----- opponents check computation start ----- //

        double distance_to_rob = sqrt(pow((opp_pos->x[i]-rob_pos->x), 2) + pow((opp_pos->y[i]-rob_pos->y), 2));
        
		if (distance_to_rob < 0.182 * 2)
		{
			//printf("check opp front, dist: %f\n", distance_to_rob);
			return 1;
		}
        
		// ----- opponents check computation end ----- //
	}

	return 0;
}

NAMESPACE_CLOSE();
