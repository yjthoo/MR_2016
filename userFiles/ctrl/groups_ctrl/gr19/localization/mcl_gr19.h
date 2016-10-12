/*! 
 * \author Group 19
 * \file mcl_gr19.h
 * \brief localization using Monte Carlo technic
 */

#ifndef _MCL_GR19_H_
#define _MCL_GR19_H_

#include "CtrlStruct_gr19.h"
#include "init_pos_gr19.h"

NAMESPACE_INIT(ctrlGr19);

/// Markov main structure
struct MCLStruct
{
	int dummy_variable; ///< put your own variable, this is just an example without purpose
};

void mcl_update(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
