/*! 
 * \author Group 15
 * \file odometry_gr15.h
 * \brief odometry of the robot
 */

#ifndef _ODOMETRY_GR15_H_
#define _ODOMETRY_GR15_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr15.h"

NAMESPACE_INIT(ctrlGr15);

void update_odometry(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
