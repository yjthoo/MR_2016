/*! 
 * \author Group 3
 * \file odometry_gr3.h
 * \brief odometry of the robot
 */

#ifndef _ODOMETRY_GR3_H_
#define _ODOMETRY_GR3_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr3.h"

NAMESPACE_INIT(ctrlGr3);

void update_odometry(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
