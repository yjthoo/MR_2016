/*! 
 * \author Group 9
 * \file calibration_gr9.h
 * \brief calibration of the robot
 */

#ifndef _CALIBRATION_GR9_H_
#define _CALIBRATION_GR9_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr9.h"

NAMESPACE_INIT(ctrlGr9);

/// robot calibration
typedef struct RobotCalibration
{
	double t_flag; ///< time for flag

	int flag; ///< flag for calibration

} RobotCalibration;

void calibration(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
