#include "speed_regulation_gr15.h"
#include "useful_gr15.h"

NAMESPACE_INIT(ctrlGr15);

/*! \brief wheel speed regulation
 * 
 * \param[in,out] cvs controller main structure
 * \parem[in] r_sp_ref right wheel speed reference [rad/s]
 * \parem[in] l_sp_ref left wheel speed reference [rad/s]
 */
void speed_regulation(CtrlStruct *cvs, double r_sp_ref, double l_sp_ref)
{
	double r_sp, l_sp, r_sp_output, l_sp_output, r_error, l_error;
	double dt;

	//control coefficients
	float k=5, ki=0.3;

	// variables declaration
	CtrlIn *inputs;
	CtrlOut *outputs;
	SpeedRegulation *sp_reg;

	// variables initialization
	inputs  = cvs->inputs;
	outputs = cvs->outputs;
	sp_reg  = cvs->sp_reg;

	// wheel speeds
	r_sp = inputs->r_wheel_speed;
	l_sp = inputs->l_wheel_speed;

	// time
	dt = inputs->t - sp_reg->last_t; // time interval since last call

	// ----- Wheels regulation computation start ----- //

	r_error = r_sp_ref - r_sp;
	l_error = l_sp_ref - l_sp;

	r_sp_output = k*r_error + ki* sp_reg->int_error_r * dt;
	l_sp_output = k*l_error + ki* sp_reg->int_error_l * dt;

	// wheel commands
	outputs->wheel_commands[R_ID] = limit_range(r_sp_output, -90, 90);
	outputs->wheel_commands[L_ID] = limit_range(l_sp_output, -90, 90);

	// ----- Wheels regulation computation end ----- //

	//update error
	sp_reg->int_error_r = r_error;
	sp_reg->int_error_l = l_error;

	// last update time
	sp_reg->last_t = inputs->t;
}

NAMESPACE_CLOSE();
