/*! 
 * \author Group 12
 * \file odometry_gr12.h
 * \brief odometry of the robot
 */

#ifndef _ODOMETRY_GR12_H_
#define _ODOMETRY_GR12_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr12.h"

NAMESPACE_INIT(ctrlGr12);

void update_odometry(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
