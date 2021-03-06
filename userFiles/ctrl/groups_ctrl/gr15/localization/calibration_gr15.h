/*! 
 * \author Group 15
 * \file calibration_gr15.h
 * \brief calibration of the robot
 */

#ifndef _CALIBRATION_GR15_H_
#define _CALIBRATION_GR15_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr15.h"

NAMESPACE_INIT(ctrlGr15);

/// robot calibration
typedef struct RobotCalibration
{
	double t_flag; ///< time for flag

	int flag; ///< flag for calibration

} RobotCalibration;

void calibration(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
