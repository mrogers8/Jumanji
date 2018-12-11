/*
 * riddle_module.c
 * Game module for special space riddle
 *
 *
 */

const int RIVER_BEGIN = 11;
const int RIVER_END = 15;
extern player_space[4];


int riddle_module(int player_num)
{
  uint16_t card_index;
  uint16_t dice_roll

  if (player_space[player_num] >= RIVER_BEGIN && player_space[player_num] <= RIVER_END){
    //lcd_play_image("DRAW RIVER CARD") //SLIDESHOW
    // RIVER DECODE
  } else {
    //lcd_play_image("DRAW A JUNGLE CARD") //SLIDESHOW
  }

  card_index = decode();

  //lcd_play_image(cardDefinitions[card_index].mpv_inst);

  int pass = 0;

  for(int i = 0; i < 3; i++) {
    if(dice_module(6) == cardDefinitions[card_index].magic_roll) {
        pass = 1;
        //lcd_play_image dice shit
        break;
    }
  }

  if(pass == 1) {
      //lcd_play_image(cardDefinitions[card_index].mpv_win);
      stepper_move_module(player_num, cardDefinitions[card_index].space_reward);
  } else {
      //lcd_play_image(cardDefinitions[card_index].mpv_lose);
      stepper_move_module(player_num, -1 * cardDefinitions[card_index].space_reward);
  }


}
