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

  // Hardware Initialization


  // Game Initialization
	// Determine player count
  num_players = 4;
	//


  //Wait for the user to indicate how many steps to move
  //printf("Enter the number of steps: ");
  //fgets(response, 79,stdin);
  //steps = strtol(response,NULL,10);

  // Set the step count reg to the value in steps
  //ece453_reg_write(STEP_COUNT_REG, steps);

 
  // Game Play
  while (!game_won) {
	// Roll Dice Module
	dice_roll = 1; //TODO add roll dice module function
		       //Interface () return dice_roll
		       // will control LCD Screen
	

	// Move Player
	//TODO add player movement module
	// Interface (starting position, ending position, player)
	//  Ret: bool   
	//  calculate vector for movement, call stepper motors/magnet


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

