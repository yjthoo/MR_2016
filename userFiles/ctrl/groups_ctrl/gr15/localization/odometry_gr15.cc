#include "odometry_gr15.h"
#include "useful_gr15.h"
#include "init_pos_gr15.h"
#include <math.h>

#define b 0.225 //distance between the two wheels
#define radius 0.030 //radius of the wheel

NAMESPACE_INIT(ctrlGr15);

/*! \brief update the robot odometry
 * 
 * \param[in,out] cvs controller main structure
 */
void update_odometry(CtrlStruct *cvs)
{
	// variables declaration
	double r_sp, l_sp, deltaS, deltaTheta, deltaX, deltaY;
	double dt;

	RobotPosition *rob_pos;
	CtrlIn *inputs;

	// variables initialization
	inputs  = cvs->inputs;
	rob_pos = cvs->rob_pos;

	r_sp = inputs->r_wheel_speed; // right wheel speed
	l_sp = inputs->l_wheel_speed; // left wheel speed

	// time
	dt = inputs->t - rob_pos->last_t; // time increment since last call

	// safety
	if (dt <= 0.0)
	{
		return;
	}

	// ----- odometry computation start ----- //

	deltaS = (r_sp*radius*dt+l_sp*radius*dt)/2;
	deltaTheta = (r_sp*radius*dt-l_sp*radius*dt)/b;
	deltaX = deltaS*cos(rob_pos->theta+deltaTheta/2);
	deltaY = deltaS*sin(rob_pos->theta+deltaTheta/2);
	rob_pos->x += deltaX;
	rob_pos->y += deltaY;
	rob_pos->theta = limit_angle(rob_pos->theta + deltaTheta);


	// ----- odometry computation end ----- //

	// last update time
	rob_pos->last_t = inputs->t;
}

NAMESPACE_CLOSE();
