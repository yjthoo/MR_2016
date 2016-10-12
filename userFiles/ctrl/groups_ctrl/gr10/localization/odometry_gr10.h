/*! 
 * \author Group 10
 * \file odometry_gr10.h
 * \brief odometry of the robot
 */

#ifndef _ODOMETRY_GR10_H_
#define _ODOMETRY_GR10_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr10.h"

NAMESPACE_INIT(ctrlGr10);

void update_odometry(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
