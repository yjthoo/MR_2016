/*! 
 * \author Group 5
 * \file path_planning_gr5.h
 * \brief path-planning algorithm
 */

#ifndef _PATH_PLANNING_GR5_H_
#define _PATH_PLANNING_GR5_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr5.h"

NAMESPACE_INIT(ctrlGr5);

/// path-planning main structure
struct PathPlanning
{
	int dummy_variable; ///< put your own variable, this is just an example without purpose
};

PathPlanning* init_path_planning();
void free_path_planning(PathPlanning *path);

NAMESPACE_CLOSE();

#endif
