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
  char step[5];
  int step_int;

  printf("trigger all the switches\n");
  electro_mag_on();
  step_y(600, 2);
  electro_mag_off();
  
  /*
  while (!buttons_read_x_min()) ;
  printf("x_min triggered\n");
  */

  int step_total = 0;
  int steps;
  /*
  while (!buttons_read_x_max()) {
    steps = 0;
    printf("Enter steps: \n");
    scanf("%d", &steps);
    step_total += steps; 
    step_x(steps, 3);
  }
  printf("x_max triggered, max range: %d\n", step_total);
  step_total = 0;
  */
 
  //stepper_reset();
  printf("MAIN: Integration Test Complete\n");
 
  return 0;

}
