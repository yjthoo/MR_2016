/*! 
 * \author Group 5
 * \file kalman_gr5.h
 * \brief localization sensors fusion with Kalman
 */

#ifndef _KALMAN_GR5_H_
#define _KALMAN_GR5_H_

#include "CtrlStruct_gr5.h"
#include "init_pos_gr5.h"

NAMESPACE_INIT(ctrlGr5);

/// Kalman main structure
struct KalmanStruc
{
	int dummy_variable; ///< put your own variable, this is just an example without purpose
};

void kalman(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
