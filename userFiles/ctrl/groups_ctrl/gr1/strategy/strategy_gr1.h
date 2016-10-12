/*! 
 * \author Group 1
 * \file strategy_gr1.h
 * \brief strategy during the game
 */

#ifndef _STRATEGY_GR1_H_
#define _STRATEGY_GR1_H_

#include "CtrlStruct_gr1.h"

NAMESPACE_INIT(ctrlGr1);

/// strategy main structure
typedef struct Strategy
{
	int main_state; ///< main state of the strategy
	
} Strategy;

/// 'main_state' states (adapt with your own states)
enum {GAME_STATE_A, GAME_STATE_B, GAME_STATE_C, GAME_STATE_D, GAME_STATE_E};

Strategy* init_strategy();
void free_strategy(Strategy *strat);
void main_strategy(CtrlStruct *cvs);

NAMESPACE_CLOSE();

#endif
