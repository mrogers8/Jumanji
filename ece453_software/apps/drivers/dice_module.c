/*
 * dice_module.c
 * Game module for dice rolls
 *
 * Returns Dice Roll
 */

 int dice_module(int roll_max)
 {

   uint16_t dice_roll;

   // Initialize the dice module
   //lcd_play_image();              //TODO: add dice image
   dice_roll = generate_number(roll_max);

   // Wait for a button press
   while (!buttons_read_all());

   //lcd_play_image();              //TODO: add dice roll image/animation

   return dice_roll;

 }
