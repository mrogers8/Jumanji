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
extern uint16_t player_space[4];

//*****************************************************************************
int main(int argc, char **argv)
{
  // Local Variables
  char response[80];
  int dice_roll;
  int button_press;

  // INITIALIZE GAME
  num_players = game_start_module();

  // Game Play
  while (!game_won) {

    // Roll Dice Module
    dice_roll = dice_module(3);;

    // Move Player
    game_won = stepper_move_module(player_turn, dice_roll);

    if (!game_won) {
      //LCD SHOW RIDDLE
      riddle_module(player_turn);
    }

  	// Go to next player
  	player_turn = (player_turn + 1) % 4;

    }


  // End Game Sequence



  return 0;
}
