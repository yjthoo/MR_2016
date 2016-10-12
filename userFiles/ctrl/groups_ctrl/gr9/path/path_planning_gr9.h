/*! 
 * \author Group 9
 * \file path_planning_gr9.h
 * \brief path-planning algorithm
 */

#ifndef _PATH_PLANNING_GR9_H_
#define _PATH_PLANNING_GR9_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr9.h"

NAMESPACE_INIT(ctrlGr9);

/// path-planning main structure
struct PathPlanning
{
	int dummy_variable; ///< put your own variable, this is just an example without purpose
};

PathPlanning* init_path_planning();
void free_path_planning(PathPlanning *path);

NAMESPACE_CLOSE();

#endif
