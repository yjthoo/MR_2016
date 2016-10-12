/*! 
 * \author Group 20
 * \file mcl_gr20.h
 * \brief localization using Monte Carlo technic
 */

#ifndef _MCL_GR20_H_
#define _MCL_GR20_H_

#include "CtrlStruct_gr20.h"
#include "init_pos_gr20.h"

NAMESPACE_INIT(ctrlGr20);

/// Markov main structure
struct MCLStruct
{
	int dummy_variable; ///< put your own variable, this is just an example without purpose
};

void mcl_update(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
