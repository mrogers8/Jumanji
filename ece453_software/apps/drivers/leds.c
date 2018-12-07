/*
 * leds.c
 */
#include "../include/leds.h"


//*****************************************************************************
// ON 
//*****************************************************************************
void leds_set_all (void)
{
  ece453_reg_write(LEDS_REG, LEDS_ALL);
}

void leds_set_red (void)
{
  int current_val;

  current_val = ece453_reg_read(LEDS_REG);
  ece453_reg_write(LEDS_REG, current_val | LEDS_RED);
}

void leds_set_orange (void)
{
  int current_val;

  current_val = ece453_reg_read(LEDS_REG);
  ece453_reg_write(LEDS_REG, current_val | LEDS_ORA);
}

void leds_set_green (void)
{
  int current_val;

  current_val = ece453_reg_read(LEDS_REG);
  ece453_reg_write(LEDS_REG, current_val | LEDS_GRE);
}

void leds_set_blue (void)
{
  int current_val;

  current_val = ece453_reg_read(LEDS_REG);
  ece453_reg_write(LEDS_REG, current_val | LEDS_BLU);
}

//*****************************************************************************
// OFF 
//*****************************************************************************
void leds_clear_all (void)
{
  ece453_reg_write(LEDS_REG, LEDS_OFF);
}

void leds_clear_red (void)
{
  int current_val;

  current_val = ece453_reg_read(LEDS_REG);
  ece453_reg_write(LEDS_REG, current_val | LEDS_RED);
}

void leds_clear_orange (void)
{
  int current_val;

  current_val = ece453_reg_read(LEDS_REG);
  ece453_reg_write(LEDS_REG, current_val | LEDS_ORA);
}

void leds_clear_green (void)
{
  int current_val;

  current_val = ece453_reg_read(LEDS_REG);
  ece453_reg_write(LEDS_REG, current_val | LEDS_GRE);
}

void leds_clear_blue (void)
{
  int current_val;

  current_val = ece453_reg_read(LEDS_REG);
  ece453_reg_write(LEDS_REG, current_val | LEDS_BLU);
}






