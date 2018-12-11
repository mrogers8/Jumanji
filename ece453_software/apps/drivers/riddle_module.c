/*
 * riddle_module.c
 * Game module for special space riddle
 *
 *
 */

#include "../include/ece453.h"

const int RIVER_BEGIN = 11;
const int RIVER_END = 15;
extern int player_space[4];


int riddle_module(int player_num)
{
  uint16_t card_index;
  uint16_t dice_roll;

  if (player_space[player_num] >= RIVER_BEGIN && player_space[player_num] <= RIVER_END){
    //lcd_play_image("DRAW RIVER CARD") //SLIDESHOW
    // RIVER DECODE
    printf("Draw a River Card\n");
  } else {
    //lcd_play_image("DRAW A JUNGLE CARD") //SLIDESHOW
    printf("Draw a Jungle Card\n");
  }

  printf("Decode Card\n");
  card_index = decode();

  //lcd_play_image(cardDefinitions[card_index].mpv_inst);
  printf("You Drew: %s\nYou need to roll a: %d\nTo move: %d\n", cardDefinitions[card_index].name, cardDefinitions[card_index].magic_roll, cardDefinitions[card_index].space_reward);


  int pass = 0;

  for(int i = 0; i < 3; i++) {
    printf("Press any button to roll");
    int dice_roll;
    if(dice_roll = dice_module(6) == cardDefinitions[card_index].magic_roll) {
        pass = 1;
        printf("You rolled a: %d\n", dice_roll);
        //lcd_play_image dice shit
        break;
    }
  }

  if(pass == 1) {
      //lcd_play_image(cardDefinitions[card_index].mpv_win);
      printf("You pass move forward: %d\n", cardDefinitions[card_index].magic_roll);
      stepper_move_module(player_num, cardDefinitions[card_index].space_reward);
  } else {
      //lcd_play_image(cardDefinitions[card_index].mpv_lose);
      printf("You fail move backword: %d\n", cardDefinitions[card_index].magic_roll);
      stepper_move_module(player_num, -1 * cardDefinitions[card_index].space_reward);
  }


}
