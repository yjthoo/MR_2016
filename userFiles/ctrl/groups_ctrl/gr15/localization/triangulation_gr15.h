/*! 
 * \author Group 15
 * \file triangulation_gr15.h
 * \brief triangulation to get the robot abgrXute position
 */

#ifndef _TRIANGULATION_GR15_H_
#define _TRIANGULATION_GR15_H_ 
 
#include "namespace_ctrl.h"
#include "CtrlStruct_gr15.h"

NAMESPACE_INIT(ctrlGr15);

void fixed_beacon_positions(int team_id, double *x_beac_1, double *y_beac_1,
	double *x_beac_2, double *y_beac_2, double *x_beac_3, double *y_beac_3);
int index_predicted(double alpha_predicted, double alpha_a, double alpha_b, double alpha_c);
void triangulation(CtrlStruct *cvs);

/// Main controller structure
typedef struct OrderRisingFalling
{
	double r1, r2, r3; //rising 1, 2 and 3
	double f1, f2, f3; //falling 1, 2 and 3

} OrderRisingFalling;

NAMESPACE_CLOSE();

#endif
