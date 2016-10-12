/*! 
 * \author Group 16
 * \file mcl_gr16.h
 * \brief localization using Monte Carlo technic
 */

#ifndef _MCL_GR16_H_
#define _MCL_GR16_H_

#include "CtrlStruct_gr16.h"
#include "init_pos_gr16.h"

NAMESPACE_INIT(ctrlGr16);

/// Markov main structure
struct MCLStruct
{
	int dummy_variable; ///< put your own variable, this is just an example without purpose
};

void mcl_update(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif