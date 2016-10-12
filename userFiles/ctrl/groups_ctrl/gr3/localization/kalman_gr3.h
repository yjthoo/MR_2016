/*! 
 * \author Group 3
 * \file kalman_gr3.h
 * \brief localization sensors fusion with Kalman
 */

#ifndef _KALMAN_GR3_H_
#define _KALMAN_GR3_H_

#include "CtrlStruct_gr3.h"
#include "init_pos_gr3.h"

NAMESPACE_INIT(ctrlGr3);

/// Kalman main structure
struct KalmanStruc
{
	int dummy_variable; ///< put your own variable, this is just an example without purpose
};

void kalman(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
