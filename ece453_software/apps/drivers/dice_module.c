/*
 * dice_module.c
 * Game module for dice rolls
 *
 * Maybe: Returns 1 if won, 0 is !won
 */
 
 void dice_module()
 {
 
   uint16_t dice_roll;
 
   // Initialize the dice module
   lcd_play_image();              //TODO: add dice image
   dice_roll = generate_number(6);
   
   // Wait for a button press
   while (!buttons_read_all());
   
   lcd_play_image();              //TODO: add dice roll image/animation
   
   stepper_move_module();
   
 }
 
