/*
 * engine.c
 * Game engine for Jumanji Game Board
 */
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include "../include/ece453.h"

//*****************************************************************************

// Gameplay Control Variables
int game_won = 0;	// 1-indexed, set to number of player
int num_players;	// valid if 1-4
int player_turn = 0;	// 0-indexed, valid if <5

// Player Position Variables
volatile int player_space[4];

//*****************************************************************************
int main(int argc, char **argv)
{
  // Local Variables
  char response[80];
  int dice_roll;
  int button_press;

  //****************************
  // Hardware Initialization
  //****************************
  //**TODO LCD_play title screen
  stepper_hw_init();
  leds_set_all();
  stepper_reset();
  //**TODO LCD play press any button to continue screen
  
  // Press any button to continue
  while (!buttons_read_all());

  //****************************
  // Game Initialization
  //****************************
  // Determine player count
  //**TODO LCD_play select players screen
  
  
  while (!(button_press = buttons_read_all())) {
	if (buttons_is_red(button_press)) 	   num_players = 1;
 	else if (buttons_is_orange(button_press))  num_players = 2;
        else if (buttons_is_green(button_press))   num_players = 3;
	else if (buttons_is_blue(button_press))    num_players = 4;
  }
  // 2 buttons do not work so this is hardcoded
  num_players = 4;
  
  

  // Game Play
  while (!game_won) {
	// Roll Dice Module
	dice_roll = ;


	// Move Player

	// Check if won (player space > value)
	if (player_space[player_turn] >= SPACE_WINNING) {
	   game_won = player_turn + 1;
	}
	
	// Show Riddle
	//TODO add riddle lcd module
	// Interface (player, position)


	// Go to next player
	player_turn = (player_turn + 1) % 4;

  }
    

  // End Game Sequence



  return 0;
}

