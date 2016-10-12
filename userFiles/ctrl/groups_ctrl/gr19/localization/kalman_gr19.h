/*! 
 * \author Group 19
 * \file kalman_gr19.h
 * \brief localization sensors fusion with Kalman
 */

#ifndef _KALMAN_GR19_H_
#define _KALMAN_GR19_H_

#include "CtrlStruct_gr19.h"
#include "init_pos_gr19.h"

NAMESPACE_INIT(ctrlGr19);

/// Kalman main structure
struct KalmanStruc
{
	int dummy_variable; ///< put your own variable, this is just an example without purpose
};

void kalman(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
