/*! 
 * \author Group 1
 * \file mcl_gr1.h
 * \brief localization using Monte Carlo technic
 */

#ifndef _MCL_GR1_H_
#define _MCL_GR1_H_

#include "CtrlStruct_gr1.h"
#include "init_pos_gr1.h"

NAMESPACE_INIT(ctrlGr1);

/// Markov main structure
struct MCLStruct
{
	int dummy_variable; ///< put your own variable, this is just an example without purpose
};

void mcl_update(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
