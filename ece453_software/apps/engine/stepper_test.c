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

extern bool complete_X;
extern bool complete_Y;

//*****************************************************************************

//*****************************************************************************
int main(int argc, char **argv)
{
  // Local Variables
  char response[80];
  int dice_roll;

  // Hardware Initialization
  stepper_hw_init();


  printf("MAIN: Test general movement\n");

//  printf("MAIN: Start Stepper Reset Test\n");
//  stepper_reset();
//  sleep(10);

  printf("MAIN: Start Stepper_Position Test\n");
  stepper_position(300, 0);
  while (!complete_X || !complete_Y);  
  sleep(3);
 
  printf("MAIN: Next\n");
 
  stepper_position(0, 0);
  while (!complete_X || !complete_Y);  
  sleep(3);

  stepper_position(0, 300);
  while (!complete_X || !complete_Y);
  sleep(3);

  stepper_position(0, 0);
  while (!complete_X || !complete_Y);
  sleep(3);

  stepper_position(1000, 1000);
  while (!complete_X || !complete_Y);
  sleep(3);

  stepper_position(500, 500);
  while (!complete_X || !complete_Y);
  sleep(3);

  stepper_position(200, 700);
  while (!complete_X || !complete_Y);
  sleep(3);

  stepper_position(700, 200);
  while (!complete_X || !complete_Y);
  sleep(3);


/*
  stepper_position(700, 700);
  sleep(5);

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


  printf("MAIN: Integration Test Complete\n");

  return 0;
}

