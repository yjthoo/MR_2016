/*! 
 * \author Group 5
 * \file odometry_gr5.h
 * \brief odometry of the robot
 */

#ifndef _ODOMETRY_GR5_H_
#define _ODOMETRY_GR5_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr5.h"

NAMESPACE_INIT(ctrlGr5);

void update_odometry(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
