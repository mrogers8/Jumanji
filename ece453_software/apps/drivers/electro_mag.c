/*
 * electro_mag.c
 */
#include "../include/electro_mag.h"


//*****************************************************************************
// electro_mag_on 
//*****************************************************************************
void electro_mag_on (void)
{
  ece453_reg_write(ELECTRO_MAG_REG, ELECTRO_MAG_ON);
  printf("DEBUG: Electro Magnet Turned On\n");
}


//*****************************************************************************
// electro_mag_off
//*****************************************************************************
void electro_mag_off (void) 
{
  ece453_reg_write(ELECTRO_MAG_REG, ELECTRO_MAG_OFF);
  printf("DEBUG: Electro Magnet Turned Off\n");
}

