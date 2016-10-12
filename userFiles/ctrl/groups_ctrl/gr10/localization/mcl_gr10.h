/*! 
 * \author Group 10
 * \file mcl_gr10.h
 * \brief localization using Monte Carlo technic
 */

#ifndef _MCL_GR10_H_
#define _MCL_GR10_H_

#include "CtrlStruct_gr10.h"
#include "init_pos_gr10.h"

NAMESPACE_INIT(ctrlGr10);

/// Markov main structure
struct MCLStruct
{
	int dummy_variable; ///< put your own variable, this is just an example without purpose
};

void mcl_update(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
