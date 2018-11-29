#ifndef __STEPPER_MOVE_H__
#define __STEPPER_MOVE_H__

#include "../include/stepper.h"
#include "../include/stepper_control.h"

//*****************************************************************************
//*****************************************************************************
int stepper_reset(void);
int stepper_position(int x, int y);

#endif
