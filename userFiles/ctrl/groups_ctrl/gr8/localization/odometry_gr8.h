/*! 
 * \author Group 8
 * \file odometry_gr8.h
 * \brief odometry of the robot
 */

#ifndef _ODOMETRY_GR8_H_
#define _ODOMETRY_GR8_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr8.h"

NAMESPACE_INIT(ctrlGr8);

void update_odometry(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
