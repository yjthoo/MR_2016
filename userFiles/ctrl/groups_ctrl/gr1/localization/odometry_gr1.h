/*! 
 * \author Group 1
 * \file odometry_gr1.h
 * \brief odometry of the robot
 */

#ifndef _ODOMETRY_GR1_H_
#define _ODOMETRY_GR1_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr1.h"

NAMESPACE_INIT(ctrlGr1);

void update_odometry(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
