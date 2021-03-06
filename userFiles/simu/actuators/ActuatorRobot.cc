#include "ActuatorRobot.hh"
#include "ctrl_io.h"
#include "config_functions.hh"
#include "config_file.h"

// actuator list
enum {ACT_RW, ACT_LW, ACT_TW, NB_ACT};

/*! \brief constructor
 * 
 * \param[in] mbs_data Robotran structure
 * \param[in] id_robot ID of the robot
 * \param[in] id_RW joint ID of the right wheel
 * \param[in] id_RL joint ID of the left wheel
 * \param[in] id_TW joint ID of the tower
 */
ActuatorRobot::ActuatorRobot(MbsData *mbs_data, int id_robot, int id_RW, int id_LW, int id_TW)
{
	FILE* config_file;
	double actuator_noise, wheel_friction, tower_friction;

	config_file = open_config();

	#ifdef HARDCODED_CONFIG
	actuator_noise = ACTUATOR_NOISE;
	wheel_friction = WHEEL_FRICTION;
	tower_friction = TOWER_FRICTION;
	#else
	actuator_noise = config_double(config_file, "actuator_noise");
	wheel_friction = config_double(config_file, "wheel_friction");
	tower_friction = config_double(config_file, "tower_friction");
	#endif

	// Actuator(mbs_data, joint_id, rho, k_phi, R, L, min_u_m, max_u_m, fric_cst, max_noise)
	for(int i=0; i<NB_ACT; i++)
	{
		switch (i)
		{
			case ACT_RW:
				// Faulhaber 024CR
				actuator_list.push_back(new Actuator(mbs_data, id_RW, 14, 26.1e-3, 7.1, 265.0-6, -24.0, 24.0, wheel_friction, actuator_noise));
				break;

			case ACT_LW:
				// Faulhaber 024CR
				actuator_list.push_back(new Actuator(mbs_data, id_LW, 14, 26.1e-3, 7.1, 265.0-6, -24.0, 24.0, wheel_friction, actuator_noise));
				break;

			case ACT_TW:
				// real characteristics unknown
				actuator_list.push_back(new Actuator(mbs_data, id_TW, 12, 7.5e-3, 2, 265.0-6, -24.0, 24.0, tower_friction, actuator_noise));
				break;

			default:
				std::cout << "Error: unknown actuator ID (" << i << ") !" << std::endl;
				exit(EXIT_FAILURE);
		}	
	}

	this->mbs_data = mbs_data;

	this->id_RW = id_RW;
	this->id_LW = id_LW;
	this->id_TW = id_TW;

	close_config(config_file);
}

/*! \brief destructor
 */
ActuatorRobot::~ActuatorRobot()
{
	for(unsigned int i=0; i<actuator_list.size(); i++)
	{
		delete actuator_list[i];
	}
}

/*! \brief compute (update) the torques generated by all the robot wheel motors
 */
void ActuatorRobot::compute_torques()
{
	for(unsigned int i=0; i<actuator_list.size(); i++)
	{
		actuator_list[i]->compute_torque();
	}
}

/*! \brief apply the torques generated by all the robot wheel motors
 */
void ActuatorRobot::apply_torques()
{
	for(unsigned int i=0; i<actuator_list.size(); i++)
	{
		actuator_list[i]->apply_torque();
	}
}

/*! \brief set the motor voltages
 *
 * \param[in] command_RW command (in [-100 ; 100]) of the right wheel
 * \param[in] command_LW command (in [-100 ; 100]) of the left wheel
 * \param[in] command_TW command (in [-100 ; 100]) of the tower
 */
void ActuatorRobot::update_voltages(double command_RW, double command_LW, double command_TW)
{
	actuator_list[ACT_RW]->update_voltage(command_RW);
	actuator_list[ACT_LW]->update_voltage(command_LW);
	actuator_list[ACT_TW]->update_voltage(command_TW);
}
