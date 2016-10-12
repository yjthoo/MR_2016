/*! 
 * \author Group 9
 * \file kalman_gr9.h
 * \brief localization sensors fusion with Kalman
 */

#ifndef _KALMAN_GR9_H_
#define _KALMAN_GR9_H_

#include "CtrlStruct_gr9.h"
#include "init_pos_gr9.h"

NAMESPACE_INIT(ctrlGr9);

/// Kalman main structure
struct KalmanStruc
{
	int dummy_variable; ///< put your own variable, this is just an example without purpose
};

void kalman(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
