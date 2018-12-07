#ifndef __STEPPER_CONTROL_H__
#define __STEPPER_CONTROL_H__

#include "../include/stepper.h"


//*****************************************************************************
// Game Board Definitions
//*****************************************************************************

#define STEPS_PER_SPACE		10   //Stepper motor steps per board space
#define SPACE_WINNING		20

//*****************************************************************************
//*****************************************************************************

// Step starting position [player]
static int SPACE_START_X[4] = {100, 200, 300, 400};
static int SPACE_START_Y[4] = {100, 200, 300, 400};

// Space containing a turn [player]
static int SPACE_TURN[4] = {3, 5, 10, 14};

// Direction of motion per [player][leg of track]
static int DIR_P_LEG[4][5] = {0, 3, 1, 2, 0,
			      0, 2, 1, 3, 0, 
			      1, 2, 0, 3, 1,
			      1, 3, 0, 2, 1};


//*****************************************************************************
//*****************************************************************************
int stepper_player_start (int player_num);

int stepper_control (int player_num, int player_start, int player_end);

int stepper_line_move (int player_num, int space_start, int space_end);

int determine_direction (int player_num, int space_start, int space_end);

#endif
