/*
 * lcd.c
 * LCD IMAGE PLAYER
 */
#include "../include/ece453.h"


//Magic Dice Numbers
// 1 = Flashlight
// 2 = Fire
// 3 = Axe
// 4 = Rope
// 5 = Sword
// 6 = Time


//*****************************************************************************
// Constants for Image File Commands
//*****************************************************************************

const Card cardDefinitions[12] = {
                                    {
                                        "RiverCrocodiles", //card name
                                        1,                //card type 1 = River 0 = Jungle
                                        3,                //number of chances to Roll
                                        3,                //number to win
                                        3,                //number of spaces to move
                                        "RGBO",
                                        "mpv --image-display-duration=10 video/RiverCrocodiles.png",   //img command
                                        "mpv --image-display-duration=10 video/RiverCrocodilesPass.png",                  //img command pass
                                        "mpv --image-display-duration=10 video/RiverCrocodilesFail.png",                  //img command fail
                                    },
                                    {
                                        "RiverFork", //card name
                                        1,                //card type 1 = River 0 = Jungle
                                        3,                //number of chances to Roll
                                        1,                //number to win
                                        1,                //number of spaces to move
                                        "RGOB",
                                        "mpv --image-display-duration=10 video/RiverFork.png",                  //img command
                                        "mpv --image-display-duration=10 video/RiverForkPass.png",                  //img command pass
                                        "mpv --image-display-duration=10 video/RiverForkFail.png",                  //img command fail
                                    },
                                    {
                                        "RiverPiranhas", //card name
                                        1,                //card type 1 = River 0 = Jungle
                                        3,                //number of chances to Roll
                                        5,                //number to win
                                        3,                //number of spaces to move
                                        "RBGO",
                                        "mpv --image-display-duration=10 video/RiverPiranhas.png",                  //img command
                                        "mpv --image-display-duration=10 video/RiverPiranhasPass.png",                  //img command pass
                                        "mpv --image-display-duration=10 video/RiverPiranhasPass.png",                  //img command fail
                                    },
                                    {
                                        "RiverRaft", //card name
                                        1,                //card type 1 = River 0 = Jungle
                                        3,                //number of chances to Roll
                                        1,                //number to win
                                        1,                //number of spaces to move
                                        "RBOG",
                                        "mpv --image-display-duration=10 video/RiverRaft.png",                  //img command
                                        "mpv --image-display-duration=10 video/RiverRaft.png",                  //img command pass
                                        "mpv --image-display-duration=10 video/RiverRaft.png",                  //img command fail
                                    },
                                    {
                                        "RiverWaterfall", //card name
                                        1,                //card type 1 = River 0 = Jungle
                                        3,                //number of chances to Roll
                                        4,                //number to win
                                        2,                //number of spaces to move
                                        "GRBO",
                                        "mpv --image-display-duration=10 video/RiverWaterfall.png",                  //img command
                                        "mpv --image-display-duration=10 video/RiverWaterfallPass.png",                  //img command pass
                                        "mpv --image-display-duration=10 video/RiverWaterfallFail.png",                  //img command fail
                                    },
                                    {
                                        "RiverWhirlpool", //card name
                                        1,                //card type 1 = River 0 = Jungle
                                        3,                //number of chances to Roll
                                        4,                //number to win
                                        2,                //number of spaces to move
                                        "GROB",
                                        "mpv --image-display-duration=10 video/RiverWhirlpool.png"                  //img command
                                        "mpv --image-display-duration=10 video/RiverWhirlpoolPass.png"                  //img command pass
                                        "mpv --image-display-duration=10 video/RiverWhirlpoolFail.png"                  //img command fail
                                    },
                                    {
                                        "JungleBats",	  //card name
                                        0,                //card type 1 = River 0 = Jungle
                                        3,                //number of chances to Roll
                                        1,                //number to win
                                        2,                //number of spaces to move
                                        "GBRO",
                                        "mpv --image-display-duration=10 video/JungleBats.png",                  //img command
                                        "mpv --image-display-duration=10 video/JungleBatsPass.png",                  //img command pass
                                        "mpv --image-display-duration=10 video/JungleBatsFail.png",                  //img command fail
                                    },
                                    {
                                        "JunglePelican",  //card name
                                        0,                //card type 1 = River 0 = Jungle
                                        3,                //number of chances to Roll
                                        4,                //number to win
                                        1,                //number of spaces to move
                                        "GBOR",
                                        "mpv --image-display-duration=10 video/JunglePelican.png",                  //img command
                                        "mpv --image-display-duration=10 video/JunglePelicanPass.png",                  //img command pass
                                        "mpv --image-display-duration=10 video/JunglePelicanFail.png",                  //img command fail
                                    },
                                    {
                                        "JunglePlants",	  //card name
                                        0,                //card type 1 = River 0 = Jungle
                                        3,                //number of chances to Roll
                                        3,                //number to win
                                        2,                //number of spaces to move
                                        "BGRO",
                                        "mpv --image-display-duration=10 video/JunglePlants.png",                  //img command
                                        "mpv --image-display-duration=10 video/JunglePlantsPass.png",                  //img command pass
                                        "mpv --image-display-duration=10 video/JunglePlantsFail.png",                  //img command fail
                                    },
                                    {
                                        "JungleSnakes",   //card name
                                        0,                //card type 1 = River 0 = Jungle
                                        3,                //number of chances to Roll
                                        5,                //number to win
                                        3,                //number of spaces to move
                                        "BGOR",
                                        "mpv --image-display-duration=10 video/JungleSnakes.png",                  //img command
                                        "mpv --image-display-duration=10 video/JungleSnakesPass.png",                  //img command pass
                                        "mpv --image-display-duration=10 video/JungleSnakesFail.png",                  //img command fail
                                    },
                                    {
                                        "JungleStampede", //card name
                                        0,                //card type 1 = River 0 = Jungle
                                        3,                //number of chances to Roll
                                        2,                //number to win
                                        3,                //number of spaces to move
                                        "BRGO",
                                        "mpv --image-display-duration=10 video/JungleStampede.png"                  //img command
                                        "mpv --image-display-duration=10 video/JungleStampedePass.png"                  //img command pass
                                        "mpv --image-display-duration=10 video/JungleStampedeFail.png"                  //img command fail
                                    },
                                    {
                                        "Quicksand",	  //card name
                                        2,                //card type 1 = River 0 = Jungle
                                        1,                //number of chances to Roll
                                        3,                //number to win
                                        0,                //number of spaces to move
                                        "OGBR",
                                        "mpv --image-display-duration=10 video/Quicksand.png"                  //img command
                                        "mpv --image-display-duration=10 video/QuicksandPass.png"                   //img command pass
                                        "mpv --image-display-duration=10 video/QuicksandFail.png"                   //img command fail
                                    }

                                };


// MPV COMMANDS PER SPACE
// All images will be stored in the ~/video directory
// --image-display-duration=# sets the time that image will display
// 		^defalut set to "inf" ie. infinity
const char * MPV_RIVER_INST[6] = {
                                "mpv --image-display-duration=10 video/RiverCrocodiles.png",
                                "mpv --image-display-duration=10 video/RiverFork.png",
                                "mpv --image-display-duration=10 video/RiverPiranhas.png",
                                "mpv --image-display-duration=10 video/RiverRaft.png",
                                "mpv --image-display-duration=10 video/RiverWaterfall.png",
                                "mpv --image-display-duration=10 video/RiverWhirlpool.png"
                             };
const char * MPV_RIVER_WIN [6] = {
                                "mpv --image-display-duration=10 video/RiverCrocodilesPass.png",
                                "mpv --image-display-duration=10 video/RiverForkPass.png",
                                "mpv --image-display-duration=10 video/RiverPiranhasPass.png",
                                "mpv --image-display-duration=10 video/RiverRaftPass.png",
                                "mpv --image-display-duration=10 video/RiverWaterfallPass.png",
                                "mpv --image-display-duration=10 video/RiverWhirlpoolPass.png"
                             };
const char * MPV_RIVER_LOSE[6] = {
                                "mpv --image-display-duration=10 video/RiverCrocodilesFail.png",
                                "mpv --image-display-duration=10 video/RiverForkFail.png",
                                "mpv --image-display-duration=10 video/RiverPiranhasFail.png",
                                "mpv --image-display-duration=10 video/RiverRaftFail.png",
                                "mpv --image-display-duration=10 video/RiverWaterfallFail.png",
                                "mpv --image-display-duration=10 video/RiverWhirlpoolFail.png"
                             };
const char * MPV_JUNGLE_INST[5] = {
                                "mpv --image-display-duration=10 video/JungleBats.png",
                                "mpv --image-display-duration=10 video/JunglePelican.png",
                                "mpv --image-display-duration=10 video/JunglePlants.png",
                                "mpv --image-display-duration=10 video/JungleSnakes.png",
                                "mpv --image-display-duration=10 video/JungleStampede.png"
};

const char * MPV_JUNGLE_WIN[5] = {
                                "mpv --image-display-duration=10 video/JungleBatsPass.png",
                                "mpv --image-display-duration=10 video/JunglePelicanPass.png",
                                "mpv --image-display-duration=10 video/JunglePlantsPass.png",
                                "mpv --image-display-duration=10 video/JungleSnakesPass.png",
                                "mpv --image-display-duration=10 video/JungleStampedePass.png"
};

const char * MPV_JUNGLE_LOSE[5] = {
                                "mpv --image-display-duration=10 video/JungleBatsFail.png",
                                "mpv --image-display-duration=10 video/JunglePelicanFail.png",
                                "mpv --image-display-duration=10 video/JunglePlantsFail.png",
                                "mpv --image-display-duration=10 video/JungleSnakesFail.png",
                                "mpv --image-display-duration=10 video/JungleStampedeFail.png"
};



const char * DICE_LAST_FRAME[6] = {
                                "mpv --image-display-duration=5 video/Roll1.png",
                                "mpv --image-display-duration=5 video/Roll2.png",
                                "mpv --image-display-duration=5 video/Roll3.png",
                                "mpv --image-display-duration=5 video/Roll4.png",
                                "mpv --image-display-duration=5 video/Roll5.png",
                                "mpv --image-display-duration=5 video/Roll6.png",


};

const char * DICE_ROLL_ANIMATION = {"mpv --playlist=video/dice_animation.pls"};

// CARD TYPE ORDERING FOR DECODING
//const Space RIVER_CARDS[6] = {RIVER_CROC};

//*****************************************************************************
// lcd_play_image
// Plays a specified image for a pre-set period of time
//
//
//*****************************************************************************
int lcd_play_space (Card card)
{

  lcd_play_image(card.mpv_inst);
  lcd_play_image(card.mpv_win);

  return 0;
}

//*****************************************************************************
// lcd_play_image
// Plays a specified image for a pre-set period of time
//
//
//*****************************************************************************
int lcd_play_image (const char * image_command)
{
   system(image_command);
   return 0;
}

int lcd_dice_roll () 
{
   system(command);
   return 0;
}
