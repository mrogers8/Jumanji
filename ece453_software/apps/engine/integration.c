/*
 * integration.c
 * Game engine integration tests
 */
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include "../include/ece453.h"
#include "../include/stepper_move.h"

//*****************************************************************************

//*****************************************************************************
int main(int argc, char **argv)
{
  // Local Variables
  char response[80];
  int dice_roll;

  // Hardware Initialization
  stepper_hw_init();



  // Roll Dice Module
  dice_roll = 1; //TODO add roll dice module function
		       //Interface () return dice_roll
		       // will control LCD Screen
	

  printf("MAIN: Test general movement\n");

//  stepper_reset();
//  sleep(10);

  stepper_position(300, 0);
  sleep(15);

  stepper_position(300, 300);

  sleep(15);


  stepper_position(1000, 1000);
  sleep(15);

/*  stepper_position(300, 300);
  sleep(15);

  stepper_position(500, 500);
  sleep(15);

  stepper_position(700, 700);
  sleep(15);

  printf("MAIN: Move to player 1 postion\n");

  stepper_player_start (0);
  sleep(15);
 
  stepper_player_start (1);
  sleep(15);
 
  stepper_player_start (2);
  sleep(15);
 
  stepper_player_start (3);
  sleep(15);
   
  printf("MAIN: Test space movement\n");
*/


  return 0;
}

