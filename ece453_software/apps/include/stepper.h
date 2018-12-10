#ifndef __STEPPER_H__
#define __STEPPER_H__

#include <signal.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <linux/types.h>
#include "../include/ece453.h"

//*****************************************************************************
// Stepper Motor contants
//*****************************************************************************

#define SIG_TEST 		44

#define STEPPER_MAX_X		4850
#define STEPPER_MAX_Y		3400

#define STEPPER_NORTH		0
#define STEPPER_SOUTH		1
#define STEPPER_EAST 		2
#define STEPPER_WEST		3

//*****************************************************************************
//*****************************************************************************
void stepper_hw_init(void);

int set_pid(void);
int clear_pid(void);

void receiveData(int n, siginfo_t *info, void *unused);

void forceStop_X(void);
void forceStop_Y(void);

int step_x(int steps, int direction);
int step_y(int steps, int direction);

#endif
