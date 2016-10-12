/*! 
 * \author Group 9
 * \file init_pos_gr9.h
 * \brief opponents position
 */

#ifndef _OPP_POS_GR9_H_
#define _OPP_POS_GR9_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr9.h"

NAMESPACE_INIT(ctrlGr9);

/// robot position
typedef struct OpponentsPosition
{
	double x[2]; ///< x position of opponents [m]
	double y[2]; ///< y position of opponents [m]

	double last_t; ///< last time the filters were updated [s]

	int nb_opp; ///< number of opponents

} OpponentsPosition;

// function prototype
int check_opp_front(CtrlStruct *cvs);
void opponents_tower(CtrlStruct *cvs);
int single_opp_tower(double last_rise, double last_fall, double rob_x, double rob_y, double rob_theta, double *new_x_opp, double *new_y_opp);

NAMESPACE_CLOSE();

#endif