/*
 * stepper_move_module.c
 * Movement Control Module after dice rolls
 *
 * Returns 1 if won, 0 if !won
 */

 uint16_t player_space[4] = {0, 0, 0, 0};

 int stepper_move_module(int player_num, int num_spaces)
 {
   int win;
   int end = player_space[player_num] + num_spaces;

   //lcd_play_image()  PLAY SPACE IMAGE

   if (end > SPACE_WINNING) {
     // STUCK
     win = 0;
   } else if (end == SPACE_WINNING) {
     win = 1;
     moveSpaces(player_num, player_space[player_num], end);
     printf("\nPLAYER %d WINS!!!\n", player_num);
   } else {
     win = 0;
     moveSpaces(player_num, player_space[player_num], end);
     player_space[player_num] += num_spaces;
   }

   return win;
 }
