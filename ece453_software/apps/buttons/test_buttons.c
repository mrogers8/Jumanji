/*
 * Cross-compile with cross-gcc -I/path/to/cross-kernel/include
 */

#include "../include/buttons.h"
#include "../include/leds.h"


//*********************************************************
//*********************************************************
int main(int argc, char *argv[])
{

  leds_clear_all();

  printf("RED\n");
  leds_set_red();

  sleep(15);

  printf("YELLOW\n");
  leds_set_orange();

  sleep(10);

  printf("GREEN\n");
  leds_set_yellow();

  sleep(10);

  printf("BLUE\n");
  leds_set_green();


  sleep(10);



  leds_clear_all();

  while (1) {
    sleep(4);
    leds_set_red();
    sleep(2);
    leds_set_orange();
    sleep(2);
    leds_clear_red();
    leds_set_yellow();
    sleep(2);
    leds_clear_orange();
    leds_set_green();

    printf("  Press Red\n");
    while (!buttons_read_red());
    leds_clear_red();

    printf("  Press Orange\n");
    while (!buttons_read_orange());
    leds_clear_orange();

    printf("  Press Yellow\n");
    while (!buttons_read_yellow());
    leds_clear_yellow();

    printf("  Press Green\n");
    while (!buttons_read_green());
    leds_clear_green();
  
    printf("  Press X_MIN\n");
    while (!buttons_read_x_min());
    
    printf("  Press X_MAX\n");
    while (!buttons_read_x_max());

    printf("  Press Y_MIN\n");
    while (!buttons_read_y_min());

    printf("  Press Y_MAX\n");
    while (!buttons_read_y_max());


  }

  
  return 1;
}

