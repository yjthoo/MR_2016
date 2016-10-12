/*! 
 * \author Group 5
 * \file init_pos_gr5.h
 * \brief initial position of the robot
 */

#ifndef _INIT_POS_GR5_H_
#define _INIT_POS_GR5_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr5.h"

NAMESPACE_INIT(ctrlGr5);

/// robot position
typedef struct RobotPosition
{
	double x; ///< x position [m]
	double y; ///< y position [m]
	double theta; ///< robot orientation [rad]

	double last_t; ///< last time position was updated

} RobotPosition;

void set_init_position(int robot_id, RobotPosition *rob_pos);

NAMESPACE_CLOSE();

#endif
