/*! 
 * \author Group 9
 * \file mcl_gr9.h
 * \brief localization using Monte Carlo technic
 */

#ifndef _MCL_GR9_H_
#define _MCL_GR9_H_

#include "CtrlStruct_gr9.h"
#include "init_pos_gr9.h"

NAMESPACE_INIT(ctrlGr9);

/// Markov main structure
struct MCLStruct
{
	int dummy_variable; ///< put your own variable, this is just an example without purpose
};

void mcl_update(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
