/*! 
 * \author Group 5
 * \file mcl_gr5.h
 * \brief localization using Monte Carlo technic
 */

#ifndef _MCL_GR5_H_
#define _MCL_GR5_H_

#include "CtrlStruct_gr5.h"
#include "init_pos_gr5.h"

NAMESPACE_INIT(ctrlGr5);

/// Markov main structure
struct MCLStruct
{
	int dummy_variable; ///< put your own variable, this is just an example without purpose
};

void mcl_update(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
