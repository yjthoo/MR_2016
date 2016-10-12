/*! 
 * \author Group 8
 * \file mcl_gr8.h
 * \brief localization using Monte Carlo technic
 */

#ifndef _MCL_GR8_H_
#define _MCL_GR8_H_

#include "CtrlStruct_gr8.h"
#include "init_pos_gr8.h"

NAMESPACE_INIT(ctrlGr8);

/// Markov main structure
struct MCLStruct
{
	int dummy_variable; ///< put your own variable, this is just an example without purpose
};

void mcl_update(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
