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

   //lcd_play_image();              //TODO: add dice roll image/animation
   printf("Roll = %d\n", dice_roll);

   return dice_roll;

 }
