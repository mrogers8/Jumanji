/*
 * game_start_module.c
 * Beginning Module for the Jumanji Game Board
 *
 * Returns number of players
 */

#include "../include/ece453.h"

int game_start_module()
{

  int button_press;
  int num_players;

  //****************************
  // Hardware Initialization
  //****************************

  //lcd_play_image();      //TODO: add start image
  printf("Welcome to Jumanji\n");
  stepper_hw_init();
  leds_set_all();
  stepper_reset();

  //lcd_play_image();       //TODO: add press any button to continue
  printf("Press any button to continue\n");
  // Press any button to continue
  while (!buttons_read_all());

  //****************************
  // Game Initialization
  //****************************
  // Determine player count

  //lcd_play_image();       //TODO: add press for the number of players
  printf("Enter number of Players RED = 1, Orange = 2, Green = 3, Blue = 4\n");

  while (!(button_press = buttons_read_all()));

	if(button_press == 8) {
            num_players = 1;
        } else if (button_press == 4) {
            num_players = 2;
        } else if (button_press == 2) {
            num_players = 3;
        } else if (button_press == 1) {
            num_players = 4;
        } else {
            return -1;
	    printf("ERROR: invalid button value\n");
        }


  printf("You have selected %d players\n", num_players);

  return num_players;
}
