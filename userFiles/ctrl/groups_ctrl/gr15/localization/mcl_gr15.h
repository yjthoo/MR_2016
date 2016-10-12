/*! 
 * \author Group 15
 * \file mcl_gr15.h
 * \brief localization using Monte Carlo technic
 */

#ifndef _MCL_GR15_H_
#define _MCL_GR15_H_

#include "CtrlStruct_gr15.h"
#include "init_pos_gr15.h"

NAMESPACE_INIT(ctrlGr15);

/// Markov main structure
struct MCLStruct
{
	int dummy_variable; ///< put your own variable, this is just an example without purpose
};

void mcl_update(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
