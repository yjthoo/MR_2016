/*! 
 * \author Group 9
 * \file odometry_gr9.h
 * \brief odometry of the robot
 */

#ifndef _ODOMETRY_GR9_H_
#define _ODOMETRY_GR9_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr9.h"

NAMESPACE_INIT(ctrlGr9);

void update_odometry(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
