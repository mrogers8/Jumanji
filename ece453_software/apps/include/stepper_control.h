#ifndef __STEPPER_CONTROL_H__
#define __STEPPER_CONTROL_H__

#include "../include/stepper.h"


//*****************************************************************************
// Game Board Definitions
//*****************************************************************************

#define STEPS_PER_SPACE		10   //Stepper motor steps per board space

//*****************************************************************************

#define SPACE_WINNING		20
//TODO add special space info

//*****************************************************************************
/*
//TODO set step values for spaces
#define SPACE_START_X 		{100, 200, 300, 400}
#define SPACE_START_Y 		{100, 200, 300, 400}

*/
//*****************************************************************************

#define SPACE_TURN_0		3    //positions when board turns
#define SPACE_TURN_1		5
#define SPACE_TURN_2		10
#define SPACE_TURN_3		14

// North 0, South 1, East 2, West 3
#define DIR_P0_LEG_0		0
#define DIR_P0_LEG_1		3
#define DIR_P0_LEG_2		1
#define DIR_P0_LEG_3		2
#define DIR_P0_LEG_4		0

#define DIR_P1_LEG_0		0
#define DIR_P1_LEG_1		2
#define DIR_P1_LEG_2		1
#define DIR_P1_LEG_3		3
#define DIR_P1_LEG_4		0

#define DIR_P2_LEG_0		1
#define DIR_P2_LEG_1		2
#define DIR_P2_LEG_2		0
#define DIR_P2_LEG_3		3
#define DIR_P2_LEG_4		1

#define DIR_P3_LEG_0		1	
#define DIR_P3_LEG_1		3
#define DIR_P3_LEG_2		0
#define DIR_P3_LEG_3		2
#define DIR_P3_LEG_4		1


//*****************************************************************************
//*****************************************************************************
int stepper_player_start (int player_num);

int stepper_control (int player_num, int player_start, int player_end);

int stepper_line_move (int player_num, int space_start, int space_end);

int determine_direction (int player_num, int space_start, int space_end);

#endif
