/*
 * LCD IMAGE PLAYER
 */
#include "../include/ece453.h"



//*****************************************************************************
// Constants for Image File Commands
//*****************************************************************************


typedef struct {
   int card_type; 		// 1 = River, 0 = Jungle
   int num_rolls;		// number of chances to roll
   int magic_roll;		// number to win
   int space_reward;		// number of space to move

   const string mpv_inst;	// image command
   const string mpv_win;
   const string mpv_lose;
} Space;


// MPV COMMANDS PER SPACE
// All images will be stored in the ~/video directory
// --image-display-duration=# sets the time that image will display
// 		^defalut set to "inf" ie. infinity
// @Brian we'll have to play with image-display configs for how long we want them to play
const string MPV_RIVER_INST[6] = {"mpv --image-display-duration=10 video/RiverCrocodiles.png", };
const string MPV_RIVER_WIN [6] = {};
const string MPV_RIVER_LOSE[6] = {};	//@Brian you can also make a struct for mpv commands 
const string MPV_JUNGLE[6] = {};	//  if that's easier and pass that to the struct

// SPACE DEFINITIONS
const Space RIVER_CROC = { 1, 3, 1, 3, MPV_RIVER_INST[0]};


// CARD TYPE ORDERING FOR DECODING
const Space[6] RIVER_CARDS = {RIVER_CROC};


//*****************************************************************************
// lcd_play_image
// Plays a specified image for a pre-set period of time
//
// 
//*****************************************************************************


int lcd_play_image (string image_command)
{
    system(image_command);

   return 0;
}



