/*! 
 * \author Group 13
 * \file calibration_gr13.h
 * \brief calibration of the robot
 */

#ifndef _CALIBRATION_GR13_H_
#define _CALIBRATION_GR13_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr13.h"

NAMESPACE_INIT(ctrlGr13);

/// robot calibration
typedef struct RobotCalibration
{
	double t_flag; ///< time for flag

	int flag; ///< flag for calibration

} RobotCalibration;

void calibration(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
