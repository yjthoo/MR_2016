#include "mcl_gr16.h"
#include "odometry_gr16.h"
#include "triangulation_gr16.h"
#include "useful_gr16.h"

NAMESPACE_INIT(ctrlGr16);

/*! \brief update using MCL technic
 * 
 * \param[in,out] cvs controller main structure
 */
void mcl_update(CtrlStruct *cvs)
{
	// variable declaration
	RobotPosition *rob_pos;

	// variables initialization
	rob_pos = cvs->rob_pos;
}

NAMESPACE_CLOSE();
