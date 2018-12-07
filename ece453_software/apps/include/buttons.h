#ifndef __BUTTONS_H__
#define __BUTTONS_H__

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
#define BUTTONS_RED 		0x8
#define BUTTONS_ORA		0x4
#define BUTTONS_GRE		0x2
#define BUTTONS_BLU		0x1

#define BUTTONS_X_MIN		0x1
#define BUTTONS_X_MAX		0x2
#define BUTTONS_Y_MIN		0x4
#define BUTTONS_Y_MAX		0x8

//*****************************************************************************
//*****************************************************************************
int buttons_read_all (void);

int buttons_read_red (void);
int buttons_read_orange (void);
int buttons_read_green (void);
int buttons_read_blue (void);

//*****************************************************************************
//*****************************************************************************
int buttons_read_x_min (void);
int buttons_read_x_max (void);
int buttons_read_y_min (void);
int buttons_read_y_max (void);

#endif

