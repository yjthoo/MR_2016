#include "calibration_gr15.h"
#include "speed_regulation_gr15.h"
#include "odometry_gr15.h"
#include "useful_gr15.h"
#include "init_pos_gr15.h"
#include <math.h>

NAMESPACE_INIT(ctrlGr15);

#define DEG_TO_RAD (M_PI/180.0) ///< convertion from degrees to radians

// calibration states
enum {CALIB_START, CALIB_STATE_A, CALIB_STATE_B, CALIB_STATE_C, CALIB_FINISH};

/*! \brief calibration of the robot to calibrate its position
 * 
 * \param[in,out] cvs controller main structure
 * 
 * This FSM can be adapted, depending on the map and on the robots initial position.
 */
void calibration(CtrlStruct *cvs)
{
	// variables declaration
	int team_id;
	double t;

	CtrlIn *inputs;
	RobotCalibration *calib;
	RobotPosition *rob_pos;

	// variables initialization
	inputs = cvs->inputs;
	calib  = cvs->calib;

	rob_pos = cvs->rob_pos;
	
	t = inputs->t;
	team_id = cvs->team_id;

	// finite state machine (FSM)
	switch (calib->flag)
	{
		case CALIB_START: // start calibration
			speed_regulation(cvs, 0.0, 0.0);

			calib->flag = CALIB_STATE_A; // directly go to state A
			calib->t_flag = t;
			break;

		case CALIB_STATE_A: // state A
			speed_regulation(cvs, -20, -20);

			// go to state B after 2 seconds
			if (t - calib->t_flag > 1.2)
			{
				calib->flag = CALIB_STATE_B;
				calib->t_flag = t;
				rob_pos->y = 1.562-0.06;
				rob_pos->theta = -90*DEG_TO_RAD;
			}
			break;

		case CALIB_STATE_B: // state B
			//mise à 0 de y et angle (robot au fond)

			//faire un quart de tour : 112.5*2*Pi/4/1000 = 0.177 m
			//vitesse : 20 rad/s => vitesse tangentielle = 20*30/1000 = 0.6 m/s
			//temps : t = d/v = 0.177/0.6 = 0.295 s => temps non suffisant car asservissement en vitesse non réglé
			speed_regulation(cvs, 20.0, 0.0);

			// go to state C after 0.295 seconds
			if (t - calib->t_flag > 1)
			{
				calib->flag = CALIB_STATE_C;

				calib->t_flag = t;
			}
			break;

		case CALIB_STATE_C: // state C

			speed_regulation(cvs, -20.0, -20.0);

			// go to final state after 2 seconds
			if (t - calib->t_flag > 1)
			{
				calib->flag = CALIB_FINISH;

				calib->t_flag = t;
			}
			break;

		case CALIB_FINISH: // wait before the match is starting
			//mise à 0 de x 
			rob_pos->x=0.562+0.06;
			speed_regulation(cvs, 0.0, 0.0);
			cvs->main_state = WAIT_INIT_STATE;
			break;
	
		default:
			printf("Error: unknown state : %d !\n", calib->flag);
			exit(EXIT_FAILURE);
	}
}

NAMESPACE_CLOSE();
