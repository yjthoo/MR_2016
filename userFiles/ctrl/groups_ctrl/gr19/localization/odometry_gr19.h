/*! 
 * \author Group 19
 * \file odometry_gr19.h
 * \brief odometry of the robot
 */

#ifndef _ODOMETRY_GR19_H_
#define _ODOMETRY_GR19_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr19.h"

NAMESPACE_INIT(ctrlGr19);

void update_odometry(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
