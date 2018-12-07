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

  uint8_t done_x = 0;
  uint8_t done_y = 0;

  printf("INFO: step_reset begin\n");
  step_y(STEPPER_MAX_Y, STEPPER_SOUTH);
  step_x(STEPPER_MAX_X, STEPPER_WEST);
 
  // Poll for button press
  printf("DEBUG: Buttons (%i, %i)\n", buttons_read_x_min(), buttons_read_y_min());
  while (!(done_x = buttons_read_x_min()) || !(done_y = buttons_read_y_min())) {
	done_y = buttons_read_y_min();
  	//printf("DEBUG: Buttons (%i, %i):done(%i, %i)\n", buttons_read_x_min(), buttons_read_y_min(), done_x, done_y);
	if (done_y) {
	   printf("DEBUG: pt1 done_y forceStop\n");
	   forceStop_Y();
	   while (!buttons_read_x_min());
	   printf("DEBUG: pt2 button_X_read forceStop\n");
	   forceStop_X();
	   break;
	} else if (done_x) {
	   printf("DEBUG: pt1 done_x forceStop\n");
	   forceStop_X();
	   while (!buttons_read_y_min());
	   printf("DEBUG: pt2 button_Y_read forceStop\n");
	   forceStop_Y();
	   break;
	}
  }

  forceStop_Y();
  forceStop_X();

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
int stepper_position (uint32_t x, uint32_t y) 
{
  printf("INFO: step_position posi begin (%d, %d)\n", x_pos, y_pos);
  printf("INFO: step_position move begin (%d, %d)\n", x, y);
  
  if (x > STEPPER_MAX_X || x < 0 || y > STEPPER_MAX_Y || x < 0) {
	printf("ERROR: Invalid x: %d, y: %d - cannot move\n", x, y);
	return 1;
  } 
 
  //Move Y
  if (y_pos > y) {
	printf("INFO: stepper_position SOUTH, y_pos: %d\n", y_pos);
	step_y( (y_pos = y_pos - y), STEPPER_SOUTH);
  } else if (y_pos < y) {
	printf("INFO: stepper_position NORTH, y_pos: %d\n", y_pos);
	step_y( (y_pos = y - y_pos), STEPPER_NORTH);
  }

 // Move X
  if (x_pos > x) {
	printf("INFO: stepper_position WEST, x_pos: %d\n", x_pos);
	step_x( (x_pos = x_pos - x), STEPPER_WEST);
  } else if (x_pos < x) {
	printf("INFO: stepper_position EAST, x_pos: %d\n", x_pos);
	step_x( (x_pos = x - x_pos), STEPPER_EAST);
  }
  return 0;
}

