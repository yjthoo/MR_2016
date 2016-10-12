/*! 
 * \author Group 6
 * \file kalman_gr6.h
 * \brief localization sensors fusion with Kalman
 */

#ifndef _KALMAN_GR6_H_
#define _KALMAN_GR6_H_

#include "CtrlStruct_gr6.h"
#include "init_pos_gr6.h"

NAMESPACE_INIT(ctrlGr6);

/// Kalman main structure
struct KalmanStruc
{
	int dummy_variable; ///< put your own variable, this is just an example without purpose
};

void kalman(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
