#ifndef __LCD_H__
#define __LCD_H__

#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>

//#include </usr/include/mpv/client.h>
//#include <mpv/client.h>

#include "ece453.h"

//*****************************************************************************
typedef struct Cards {
   char * name;         //card name
   int card_type;               // 2 = special 1 = River, 0 = Jungle
   int num_rolls;               // number of chances to roll
   int magic_roll;              // number to win
   int space_reward;            // number of space to move

   char code[4];

   const char * mpv_inst;       // image command
   const char * mpv_win;
   const char * mpv_lose;
} Card;

extern const Card cardDefinitions[12];

extern const char * MPV_RIVER_INST[6];
extern const char * MPV_RIVER_WIN[6];
extern const char * MPV_RIVER_LOSE[6];
extern const char * MPV_JUNGLE_INST[5];
extern const char * MPV_JUNGLE_WIN[5];
extern const char * MPV_JUNGLE_LOSE[5];


//*****************************************************************************
int lcd_play_space(Card card);
int lcd_play_image (const char * image_command);


#endif
