/*! 
 * \author Group 16
 * \file calibration_gr16.h
 * \brief calibration of the robot
 */

#ifndef _CALIBRATION_GR16_H_
#define _CALIBRATION_GR16_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr16.h"

NAMESPACE_INIT(ctrlGr16);

/// robot calibration
typedef struct RobotCalibration
{
	double t_flag; ///< time for flag

	int flag; ///< flag for calibration

} RobotCalibration;

void calibration(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
