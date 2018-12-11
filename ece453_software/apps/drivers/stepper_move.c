/*
 * stepper_move.c
 * General motion control functions
 */
#include "../include/stepper_move.h"

int x_pos;
int y_pos;

//starting Space for each player
int x_1 = 550;
int x_2 = 550;
int x_3 = 4100;
int x_4 = 4100;

int y_1 = 2650;
int y_2 = 750;
int y_3 = 2650;
int y_4 = 750;

int offset = 350; //number of steps between spaces

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
	step_x( (x_pos = x_pos - x), STEPPER_WEST);
  } else {
	step_x( (x_pos = x - x_pos), STEPPER_EAST);
  }

  //Move Y
  if (y_pos > y) {
	step_y( (y_pos = y_pos - y), STEPPER_SOUTH);
  } else {
	step_y( (y_pos = y - y_pos), STEPPER_NORTH);
  }

  return 0;
}

//*****************************************************************************
//  move
//  Move to a specific positon on the board based on current board step_position
// Turns on magnet and waits for completion
//
//  Input step values and a 1 or 0 for magnet on or off
//  Return: 1
//*****************************************************************************
int move(int x, int y, int mag) {
  if(mag == 1) {
    electro_mag_on();
  }
  stepper_position(x, y, x_pos, y_pos);
  x_pos = x;
  y_pos = y;
  while (!complete_X || !complete_Y);
  sleep(1);
  electro_mag_off();
  return 1;
}


//*****************************************************************************
//  move
//  Move to a specific positon on the board based on current board step_position
// Turns on magnet and waits for completion
//
//  Input: Player to move, Which track it is on 1 - 5 starting from the begineing,
//         moveNum number of spaces to move
//  Return: 1
//*****************************************************************************
int movePath(int player, int run, int moveNum) {

  switch (run)
  {
    case 1:

    switch (player)
    {
        case 1:
            move(x_1, y_1, 0);
            move(x_1 = x_1 + offset * moveNum, y_1, 1);
            break;

        case 2:
            move(x_2, y_2, 0);
            move(x_2 = x_2 + offset * moveNum, y_2, 1);
            break;

        case 3:
        move(x_3, y_3, 0);
           move(x_3 = x_3 - offset * moveNum, y_3, 1);
        break;

        case 4:
            move(x_4, y_4, 0);
            move(x_4 = x_4 - offset * moveNum, y_4, 1);
            break;
    }
    break;

    case 2:
      switch (player)
      {
          case 1:
              move(x_1, y_1, 0);
              move(x_1, y_1 = y_1 + offset * moveNum, 1);
              break;

          case 2:
              move(x_2, y_2, 0);
              move(x_2, y_2 = y_2 - offset * moveNum, 1);
              break;

          case 3:
              move(x_3, y_3, 0);
              move(x_3, y_3 = y_3 + offset * moveNum, 1);
              break;

          case 4:
              move(x_4, y_4, 0);
              move(x_4, y_4 = y_4 - offset * moveNum, 1);
              break;
      }
    break;

    case 3:
      switch (player)
      {
          case 1:
              move(x_1, y_1, 0);
              move(x_1 = x_1 - offset * moveNum + 31, y_1, 1);
              break;

          case 2:
              move(x_2, y_2, 0);
              move(x_2 = x_2 - offset * moveNum + 31, y_2, 1);
              break;

          case 3:
              move(x_3, y_3, 0);
              move(x_3 = x_3 + offset * moveNum, y_3, 1);
              break;

          case 4:
              move(x_4, y_4, 0);
              move(x_4 = x_4 + offset * moveNum, y_4, 1);
              break;
      }
    break;

    case 4:
      switch (player)
      {
          case 1:
              move(x_1, y_1, 0);
            move(x_1, y_1 = y_1 - offset * moveNum, 1);
              break;

          case 2:
              move(x_2, y_2, 0);
              move(x_2, y_2 = y_2 + offset * moveNum, 1);
              break;

          case 3:
              move(x_3, y_3, 0);
              move(x_3, y_3 = y_3 - offset * moveNum, 1);
              break;

          case 4:
              move(x_4, y_4, 0);
              move(x_4, y_4 = y_4 + offset * moveNum, 1);
              break;
      }
    break;

    case 5:
      switch (player)
      {
          case 1:
              move(x_1, y_1, 0);
              move(x_1 = x_1 + offset * moveNum, y_1, 1);
              break;

          case 2:
              move(x_2, y_2, 0);
              move(x_2 = x_2 + offset * moveNum, y_2, 1);
              break;

          case 3:
              move(x_3, y_3, 0);
              move(x_3 = x_3 - offset * moveNum, y_3, 1);
              break;

          case 4:
              move(x_4, y_4, 0);
              move(x_4 = x_4 - offset * moveNum, y_4, 1);
              break;
      }
    break;
  }
}

//*****************************************************************************
//  moveSpaces
//  Move a players peice from start space to end space
//
//  Input: Player to move, start space, end space
//  Return: 1
//*****************************************************************************

    int moveSpaces(int player, int startSpace, int endSpace) {
        if(startSpace - endSpace >= 0) {
            for(int i = startSpace; i < endSpace; i++) {
              if(i < 4) {
                movePath(player, 1, 1);
              } else if (i >= 4 && i < 6) {
                  movePath(player, 2, 1);
              } else if (i >= 6 && i < 11) {
                  movePath(player, 3, 1);
              } else if (i >= 11 && i < 15) {
                  movePath(player, 4, 1);
              } else if (i >= 15 && i < 20) {
                  movePath(player, 5, 1);
              } else {

              }
            }
        } else {
            for(int i = startSpace; i < endSpace; i++) {
                if (i >= 15 && i < 20) {
                    movePath(player, 5, -1);
                } else if (i >= 11 && i < 15) {
                    movePath(player, 4, -1);
                } else if (i >= 6 && i < 11) {
                    movePath(player, 3, -1);
                } else if (i >= 4 && i < 6) {
                    movePath(player, 2, -1);
                } else if(i < 4) {
                   movePath(player, 1, -1);
                } else {

                }
            }
        }
        return 1;
    }
