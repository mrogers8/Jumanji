/*
 * stepper_move.c
 * General motion control functions
 */
#include "../include/stepper_move.h"

int x_pos = 0;
int y_pos = 0;

//*****************************************************************************
//  stepper_reset
//  Reset Stepper Motor Unit to (0,0)
//
//  Return: 0 for success, 1 for failure
//*****************************************************************************
int stepper_reset (void) 
{

  int done_x, done_y;

  printf("INFO: step_reset begin\n");
  step_x(STEPPER_MAX, STEPPER_SOUTH);
  step_y(STEPPER_MAX, STEPPER_WEST);

  // Poll for button press
  while (!(done_x = buttons_read_x_min()) || !(done_y = buttons_read_y_min())) {
	if (done_x) {
	   forceStop_X();
	   while (!buttons_read_y_min());
	   forceStop_Y();
	} else {
	   forceStop_Y();
	   while (!buttons_read_x_min());
	   forceStop_X();
	}
  }

  x_pos = 0;
  y_pos = 0;

  return 1;
}

//*****************************************************************************
//  stepper_position
//  Move to a specific positon on the board based on current board position
//
//  Input as step values
//  Return: 0 for success, 1 for failure
//*****************************************************************************
int stepper_position (int x, int y) 
{
  printf("INFO: step_position begin (%d, %d)\n", x, y);

  if (x > STEPPER_MAX || x < 0 || y > STEPPER_MAX || x < 0) {
	printf("ERROR: Invalid x: %d, y: %d - cannot move\n");
	return 1;
  } 
  // Move X
  if (x_pos > x) {
	printf("INFO: stepper_position WEST, x_pos: %d\n", x_pos);
	step_x( (x_pos = x_pos - x), STEPPER_WEST);
  } else {
	printf("INFO: stepper_position EAST, x_pos: %d\n", x_pos);
	step_x( (x_pos = x - x_pos), STEPPER_EAST);
  }

  //Move Y
  if (y_pos > y) {
	printf("INFO: stepper_position SOUTH, y_pos: %d\n", y_pos);
	step_y( (y_pos = y_pos - y), STEPPER_SOUTH);
  } else {
	printf("INFO: stepper_position NORTH, y_pos: %d\n", y_pos);
	step_y( (y_pos = y - y_pos), STEPPER_NORTH);
  }

  return 0;
}

