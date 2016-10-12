/*! 
 * \author Group 13
 * \file odometry_gr13.h
 * \brief odometry of the robot
 */

#ifndef _ODOMETRY_GR13_H_
#define _ODOMETRY_GR13_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr13.h"

NAMESPACE_INIT(ctrlGr13);

void update_odometry(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
