/*! 
 * \author Group 16
 * \file odometry_gr16.h
 * \brief odometry of the robot
 */

#ifndef _ODOMETRY_GR16_H_
#define _ODOMETRY_GR16_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr16.h"

NAMESPACE_INIT(ctrlGr16);

void update_odometry(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
