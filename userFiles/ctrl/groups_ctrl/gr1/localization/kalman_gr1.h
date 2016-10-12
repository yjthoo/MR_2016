/*! 
 * \author Group 1
 * \file kalman_gr1.h
 * \brief localization sensors fusion with Kalman
 */

#ifndef _KALMAN_GR1_H_
#define _KALMAN_GR1_H_

#include "CtrlStruct_gr1.h"
#include "init_pos_gr1.h"

NAMESPACE_INIT(ctrlGr1);

/// Kalman main structure
struct KalmanStruc
{
	int dummy_variable; ///< put your own variable, this is just an example without purpose
};

void kalman(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
