/*
 * Cross-compile with cross-gcc -I/path/to/cross-kernel/include
 */

#include "../include/electro_mag.h"

//*********************************************************
//*********************************************************
int main(int argc, char *argv[])
{

  while(1) {
  printf("Mag On\n");
  electro_mag_on();

  sleep(8);
  
  electro_mag_off();
  printf("Mag Off\n");
  
  sleep(5);
  }

  return 1;
}

