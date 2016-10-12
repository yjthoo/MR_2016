/*! 
 * \author Group 3
 * \file mcl_gr3.h
 * \brief localization using Monte Carlo technic
 */

#ifndef _MCL_GR3_H_
#define _MCL_GR3_H_

#include "CtrlStruct_gr3.h"
#include "init_pos_gr3.h"

NAMESPACE_INIT(ctrlGr3);

/// Markov main structure
struct MCLStruct
{
	int dummy_variable; ///< put your own variable, this is just an example without purpose
};

void mcl_update(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
