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
#include "../include/electro_mag.h"

extern bool complete_X;
extern bool complete_Y;

int x_pos = 0;
int y_pos = 0;

int x_1 = 550;
int x_2 = 550;
int x_3 = 4100;
int x_4 = 4100;

int y_1 = 2650;
int y_2 = 750;
int y_3 = 2650;
int y_4 = 750;



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

//*****************************************************************************
int main(int argc, char **argv)
{
  // Local Variables
  char response[80];
  int dice_roll;

  // Hardware Initialization
  stepper_hw_init();


  printf("MAIN: Testing Reset\n");
  stepper_reset();
  sleep(10);
  printf("MAIN: Stepper reset complete\n");

  int offset = 350;

  /*for(int i = 0; i < 3; i++) {
    move(x_1, y_1, 0);
    move(x_1 = x_1 + offset, y_1, 1);
    move(x_2, y_2, 0);
    move(x_2 = x_2 + offset, y_2, 1);
    move(x_3, y_3, 0);
    move(x_3 = x_3 - offset, y_3, 1);
    move(x_4, y_4, 0);
    move(x_4 = x_4 - offset, y_4, 1);
  }*/
//
  /*  move(x_1, y_1, 0);
    move(x_1 = x_1 + offset * 3, y_1, 1);
    move(x_2, y_2, 0);
    move(x_2 = x_2 + offset * 3, y_2, 1);
    move(x_3, y_3, 0);
    move(x_3 = x_3 - offset * 3, y_3, 1);
    move(x_4, y_4, 0);
    move(x_4 = x_4 - offset * 3, y_4, 1);

    move(x_1, y_1, 0);
    move(x_1, y_1 = y_1 + offset * 2, 1);
    move(x_2, y_2, 0);
    move(x_2, y_2 = y_2 - offset * 2, 1);
    move(x_3, y_3, 0);
    move(x_3, y_3 = y_3 + offset * 2, 1);
    move(x_4, y_4, 0);
    move(x_4, y_4 = y_4 - offset * 2, 1);
    */

/*1*/
    move(x_1, y_1, 0);
    move(x_1 = x_1 + offset * 3, y_1, 1);
    move(x_1, y_1 = y_1 + offset * 2, 1);
    move(x_1 = x_1 - offset * 5 + 151, y_1, 1);
    move(x_1, y_1 = y_1 - offset * 4, 1);
    move(x_1 = x_1 + offset * 5, y_1, 1);


/*2*/    move(x_2, y_2, 0);
    move(x_2 = x_2 + offset * 3, y_2, 1);
    move(x_2, y_2 = y_2 - offset * 2, 1);
    move(x_2 = x_2 - offset * 5 + 151, y_2, 1);
    move(x_2, y_2 = y_2 + offset * 4, 1);
    move(x_2 = x_2 + offset * 5, y_2, 1);


/*3*/    move(x_3, y_3, 0);
    move(x_3 = x_3 - offset * 3, y_3, 1);
    move(x_3, y_3 = y_3 + offset * 2, 1);
    move(x_3 = x_3 + offset * 5, y_3, 1);
    move(x_3, y_3 = y_3 - offset * 4, 1);
    move(x_3 = x_3 - offset * 5, y_3, 1);

/*4*/
    move(x_4, y_4, 0);
    move(x_4 = x_4 - offset * 3, y_4, 1);
    move(x_4, y_4 = y_4 - offset * 2, 1);
    move(x_4 = x_4 + offset * 5, y_4, 1);
    move(x_4, y_4 = y_4 + offset * 4, 1);
    move(x_4 = x_4 - offset * 5, y_4, 1);

  while(1) {

    int x;
    int y;
    int m;

     printf("Please input an X value: ");
     scanf("%d", &x);
     printf("Please enter an Y value: ");
     scanf("%d", &y);
     printf("Magnet On?: ");
     scanf("%d", &m);
     if(x != 0 || y != 0) {
       if(m == 1) {
         electro_mag_on();
       }
       printf("Moving to: %d, %d", x, y);
       stepper_position(x, y, x_pos, y_pos);
       x_pos = x;
       y_pos = y;
       while (!complete_X || !complete_Y);
       sleep(3);
       electro_mag_off();
     } else {
       printf("Reseting/n");
       stepper_reset();
       x_pos = 0;
       y_pos = 0;
       electro_mag_off();
     }

  }

//  printf("MAIN: Start Stepper Reset Test\n");
//  stepper_reset();
//  sleep(10);
/*
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

*/
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
