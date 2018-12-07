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
  stepper_position(0, 10);
  while (!complete_X || !complete_Y);  
  sleep(3);

  electro_mag_on();
 
  stepper_position(0, 1000);
  while (!complete_X || !complete_Y);

  stepper_position(0, 0);
  while (!complete_X || !complete_Y);

  stepper_position(0, 1000);
  while (!complete_X || !complete_Y);

  electro_mag_off();

  stepper_position(0, 0);
  while (!complete_X || !complete_Y);

  printf("MAIN: Integration Test Complete\n");

  return 0;
}

