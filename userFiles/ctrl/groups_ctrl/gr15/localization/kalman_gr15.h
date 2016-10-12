/*! 
 * \author Group 15
 * \file kalman_gr15.h
 * \brief localization sensors fusion with Kalman
 */

#ifndef _KALMAN_GR15_H_
#define _KALMAN_GR15_H_

#include "CtrlStruct_gr15.h"
#include "init_pos_gr15.h"

NAMESPACE_INIT(ctrlGr15);

/// Kalman main structure
struct KalmanStruc
{
	int dummy_variable; ///< put your own variable, this is just an example without purpose
};

void kalman(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
