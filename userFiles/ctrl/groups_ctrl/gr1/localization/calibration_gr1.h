/*! 
 * \author Group 1
 * \file calibration_gr1.h
 * \brief calibration of the robot
 */

#ifndef _CALIBRATION_GR1_H_
#define _CALIBRATION_GR1_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr1.h"

NAMESPACE_INIT(ctrlGr1);

/// robot calibration
typedef struct RobotCalibration
{
	double t_flag; ///< time for flag

	int flag; ///< flag for calibration

} RobotCalibration;

void calibration(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
