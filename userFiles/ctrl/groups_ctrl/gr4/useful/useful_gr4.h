/*! 
 * \author Group 4
 * \file useful_gr4.h
 * \brief useful functions to use in the controller
 */

#ifndef _USEFUL_GR4_H_
#define _USEFUL_GR4_H_

#include "namespace_ctrl.h"

NAMESPACE_INIT(ctrlGr4);

double rnd();
double norm_dist(double dx, double dy);
double limit_range(double x, double min, double max);
double limit_angle(double x);
double first_order_filter(double last_val, double new_val, double tau, double delta_t);

NAMESPACE_CLOSE();

#endif
