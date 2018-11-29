#ifndef __LEDS_H__
#define __LEDS_H__

#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include "ece453.h"

//*****************************************************************************
// Stepper Motor input value contants
//*****************************************************************************
#define LEDS_OFF		0x0
#define LEDS_RED 		0x1
#define LEDS_ORA		0x2
#define LEDS_YEL		0x4
#define LEDS_GRE		0x8
#define LEDS_ALL		0xF

//*****************************************************************************
//*****************************************************************************
void leds_set_red (void);
void leds_set_orange (void);
void leds_set_yellow (void);
void leds_set_green (void);

void leds_clear_red (void);
void leds_clear_orange (void);
void leds_clear_yellow (void);
void leds_clear_green (void);

void leds_set_all (void);
void leds_clear_all (void);

#endif

