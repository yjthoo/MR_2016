/*! 
 * \author Group 10
 * \file calibration_gr10.h
 * \brief calibration of the robot
 */

#ifndef _CALIBRATION_GR10_H_
#define _CALIBRATION_GR10_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr10.h"

NAMESPACE_INIT(ctrlGr10);

/// robot calibration
typedef struct RobotCalibration
{
	double t_flag; ///< time for flag

	int flag; ///< flag for calibration

} RobotCalibration;

void calibration(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
