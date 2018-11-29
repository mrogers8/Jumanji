#ifndef __ELECTRO_MAG_H__
#define __ELECTRO_MAG_H__

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
#define ELECTRO_MAG_ON 		0x1
#define ELECTRO_MAG_OFF		0x0

//*****************************************************************************
//*****************************************************************************
void electro_mag_on(void);

//*****************************************************************************
//*****************************************************************************
void electro_mag_off(void);

#endif

