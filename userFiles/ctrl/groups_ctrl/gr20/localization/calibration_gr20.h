/*! 
 * \author Group 20
 * \file calibration_gr20.h
 * \brief calibration of the robot
 */

#ifndef _CALIBRATION_GR20_H_
#define _CALIBRATION_GR20_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr20.h"

NAMESPACE_INIT(ctrlGr20);

/// robot calibration
typedef struct RobotCalibration
{
	double t_flag; ///< time for flag

	int flag; ///< flag for calibration

} RobotCalibration;

void calibration(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
