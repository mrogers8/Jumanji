/*
 * dice_module.c
 * Game module for dice rolls
 *
 * Returns Dice Roll
 */
#include "../include/ece453.h"

 int dice_module(int roll_max)
 {

   uint16_t dice_roll;

   // Initialize the dice module
   //lcd_play_image();              //TODO: add dice image
   dice_roll = generate_number(roll_max);

   // Wait for a button press
   printf("Press button to roll\n");
   while (!buttons_read_all());
   
   lcd_dice_roll() ;              //TODO: add dice roll image/animation
   
   // Display the last frame of the dice (the actuall rolled number)
   switch(dice_roll) {
     case 1:
       lcd_play_image(DICE_LAST_FRAME[0]);

     case 2:
       lcd_play_image(DICE_LAST_FRAME[1]);

     case 3:
       lcd_play_image(DICE_LAST_FRAME[2]);

     case 4:
       lcd_play_image(DICE_LAST_FRAME[3]);

     case 5:
       lcd_play_image(DICE_LAST_FRAME[4]);

     case 6:
       lcd_play_image(DICE_LAST_FRAME[5]);
   }

   printf("Roll = %d\n", dice_roll);

   return dice_roll;

}
