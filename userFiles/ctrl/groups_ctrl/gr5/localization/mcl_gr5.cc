#include "mcl_gr5.h"
#include "odometry_gr5.h"
#include "triangulation_gr5.h"
#include "useful_gr5.h"

NAMESPACE_INIT(ctrlGr5);

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
