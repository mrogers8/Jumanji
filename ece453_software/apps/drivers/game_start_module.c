/*
 * game_start_module.c
 * Beginning Module for the Jumanji Game Board
 *
 * Returns number of players
 */

int game_start_module()
{
  //****************************
  // Hardware Initialization
  //****************************

  //lcd_play_image();      //TODO: add start image
  stepper_hw_init();
  leds_set_all();
  stepper_reset();

  //lcd_play_image();       //TODO: add press any button to continue

  // Press any button to continue
  while (!buttons_read_all());

  //****************************
  // Game Initialization
  //****************************
  // Determine player count

  //lcd_play_image();       //TODO: add press for the number of players

  while (!(button_press = buttons_read_all())) {
	if      (buttons_is_red(button_press)) 	   num_players = 1;
 	else if (buttons_is_orange(button_press))  num_players = 2;
  else if (buttons_is_green(button_press))   num_players = 3;
	else if (buttons_is_blue(button_press))    num_players = 4;
  }

  // TODO: button does not work so this is hardcoded
  num_players = 4;

  return num_players;
}
