/*! 
 * \author Group 19
 * \file calibration_gr19.h
 * \brief calibration of the robot
 */

#ifndef _CALIBRATION_GR19_H_
#define _CALIBRATION_GR19_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr19.h"

NAMESPACE_INIT(ctrlGr19);

/// robot calibration
typedef struct RobotCalibration
{
	double t_flag; ///< time for flag

	int flag; ///< flag for calibration

} RobotCalibration;

void calibration(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
