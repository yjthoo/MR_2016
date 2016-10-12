/*! 
 * \author Group 12
 * \file kalman_gr12.h
 * \brief localization sensors fusion with Kalman
 */

#ifndef _KALMAN_GR12_H_
#define _KALMAN_GR12_H_

#include "CtrlStruct_gr12.h"
#include "init_pos_gr12.h"

NAMESPACE_INIT(ctrlGr12);

/// Kalman main structure
struct KalmanStruc
{
	int dummy_variable; ///< put your own variable, this is just an example without purpose
};

void kalman(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
