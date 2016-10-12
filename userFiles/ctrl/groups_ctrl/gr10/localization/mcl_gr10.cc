#include "mcl_gr10.h"
#include "odometry_gr10.h"
#include "triangulation_gr10.h"
#include "useful_gr10.h"

NAMESPACE_INIT(ctrlGr10);

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
