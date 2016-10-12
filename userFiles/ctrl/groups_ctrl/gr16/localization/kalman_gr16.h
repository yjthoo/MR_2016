/*! 
 * \author Group 16
 * \file kalman_gr16.h
 * \brief localization sensors fusion with Kalman
 */

#ifndef _KALMAN_GR16_H_
#define _KALMAN_GR16_H_

#include "CtrlStruct_gr16.h"
#include "init_pos_gr16.h"

NAMESPACE_INIT(ctrlGr16);

/// Kalman main structure
struct KalmanStruc
{
	int dummy_variable; ///< put your own variable, this is just an example without purpose
};

void kalman(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
