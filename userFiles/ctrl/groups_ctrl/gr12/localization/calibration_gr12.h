/*! 
 * \author Group 12
 * \file calibration_gr12.h
 * \brief calibration of the robot
 */

#ifndef _CALIBRATION_GR12_H_
#define _CALIBRATION_GR12_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr12.h"

NAMESPACE_INIT(ctrlGr12);

/// robot calibration
typedef struct RobotCalibration
{
	double t_flag; ///< time for flag

	int flag; ///< flag for calibration

} RobotCalibration;

void calibration(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
