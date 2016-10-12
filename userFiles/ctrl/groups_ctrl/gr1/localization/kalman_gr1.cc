#include "kalman_gr1.h"
#include "odometry_gr1.h"
#include "triangulation_gr1.h"
#include "useful_gr1.h"

NAMESPACE_INIT(ctrlGr1);

/*! \brief follow a given path
 * 
 * \param[in,out] cvs controller main structure
 */
void kalman(CtrlStruct *cvs)
{
	// variable declaration
	RobotPosition *rob_pos;
	RobotPosition *triang_pos;

	// variables initialization
	rob_pos = cvs->rob_pos;
	triang_pos = cvs->triang_pos;
}

NAMESPACE_CLOSE();
