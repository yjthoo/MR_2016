/*! 
 * \author Group 3
 * \file calibration_gr3.h
 * \brief calibration of the robot
 */

#ifndef _CALIBRATION_GR3_H_
#define _CALIBRATION_GR3_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr3.h"

NAMESPACE_INIT(ctrlGr3);

/// robot calibration
typedef struct RobotCalibration
{
	double t_flag; ///< time for flag

	int flag; ///< flag for calibration

} RobotCalibration;

void calibration(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
