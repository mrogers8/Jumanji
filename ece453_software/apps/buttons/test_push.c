/*
 * Cross-compile with cross-gcc -I/path/to/cross-kernel/include
 */

#include "../include/buttons.h"
#include "../include/leds.h"


//*********************************************************
//*********************************************************
int main(int argc, char *argv[])
{
  leds_set_all();

  while (1) {

/*    printf("  Press Red\n");
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
*/  
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

