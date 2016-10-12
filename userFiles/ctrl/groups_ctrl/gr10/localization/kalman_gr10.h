/*! 
 * \author Group 10
 * \file kalman_gr10.h
 * \brief localization sensors fusion with Kalman
 */

#ifndef _KALMAN_GR10_H_
#define _KALMAN_GR10_H_

#include "CtrlStruct_gr10.h"
#include "init_pos_gr10.h"

NAMESPACE_INIT(ctrlGr10);

/// Kalman main structure
struct KalmanStruc
{
	int dummy_variable; ///< put your own variable, this is just an example without purpose
};

void kalman(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
