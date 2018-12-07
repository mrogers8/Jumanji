/*
 * Basic test for lcd screen (must be run in lxde terminal)
 */

#include <stdlib.h>
#include "../include/ece453.h"


//*********************************************************
//*********************************************************
int main(int argc, char *argv[])
{
/*
  image_obj image;
  image.file_name = "RiverCrocodiles.png";
  image.option_string = "input-default-bindings";
  image.play_time = 100;

  lcd_play_image(image);
*/

  // Old working interface
  const char *command = "mpv video/RiverCrocodiles.png";
  system(command);


  // To be changed to this interface
  

  return 0;
}

