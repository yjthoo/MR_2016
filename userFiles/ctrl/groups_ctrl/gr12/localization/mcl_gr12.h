/*! 
 * \author Group 12
 * \file mcl_gr12.h
 * \brief localization using Monte Carlo technic
 */

#ifndef _MCL_GR12_H_
#define _MCL_GR12_H_

#include "CtrlStruct_gr12.h"
#include "init_pos_gr12.h"

NAMESPACE_INIT(ctrlGr12);

/// Markov main structure
struct MCLStruct
{
	int dummy_variable; ///< put your own variable, this is just an example without purpose
};

void mcl_update(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
