/*! 
 * \author Group 5
 * \file calibration_gr5.h
 * \brief calibration of the robot
 */

#ifndef _CALIBRATION_GR5_H_
#define _CALIBRATION_GR5_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr5.h"

NAMESPACE_INIT(ctrlGr5);

/// robot calibration
typedef struct RobotCalibration
{
	double t_flag; ///< time for flag

	int flag; ///< flag for calibration

} RobotCalibration;

void calibration(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
