#ifndef __STEPPER_MOVE_H__
#define __STEPPER_MOVE_H__

#include "../include/stepper.h"
#include "../include/stepper_control.h"

//*****************************************************************************
//*****************************************************************************
int stepper_reset(void);
int stepper_position(uint32_t x, uint32_t y);
int move(uint32_t x, uint32_t y, uint32_t mag);
int movePath(uint32_t player, uint32_t run, uint32_t moveNum);
int moveSpaces(uint32_t player, uint32_t startSpace, uint32_t endSpace);

#endif
