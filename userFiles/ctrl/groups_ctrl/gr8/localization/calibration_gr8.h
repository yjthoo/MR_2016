/*! 
 * \author Group 8
 * \file calibration_gr8.h
 * \brief calibration of the robot
 */

#ifndef _CALIBRATION_GR8_H_
#define _CALIBRATION_GR8_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr8.h"

NAMESPACE_INIT(ctrlGr8);

/// robot calibration
typedef struct RobotCalibration
{
	double t_flag; ///< time for flag

	int flag; ///< flag for calibration

} RobotCalibration;

void calibration(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
