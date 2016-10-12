/*! 
 * \author Group 13
 * \file kalman_gr13.h
 * \brief localization sensors fusion with Kalman
 */

#ifndef _KALMAN_GR13_H_
#define _KALMAN_GR13_H_

#include "CtrlStruct_gr13.h"
#include "init_pos_gr13.h"

NAMESPACE_INIT(ctrlGr13);

/// Kalman main structure
struct KalmanStruc
{
	int dummy_variable; ///< put your own variable, this is just an example without purpose
};

void kalman(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
