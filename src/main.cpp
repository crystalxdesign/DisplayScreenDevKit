#include "main.h"

int main() 
{
  // Initialise the display - Note HCMODU0246 must be reset after powering up!
  ScreenInit();  // Software SPI option - slower but more compatible
  
  // Uncomment if screen contrast needs adjusting (contrast = 0 to 255)
  Contrast(16);

  while(true){
    Clear();
    graph();
    delay(500);
  }
// Display an intro
/*Intro();   

  // Scroll some text inside a box
  ScrollInABox();

  // Print random hellos with the screen in its normal orientation
  Flip(SCREEN_NORMAL);
  randomHello();                

  // Print random hellos with the screen rotated 90 degrees 
  Flip(SCREEN_R90);
  randomHello();

  // Print random hellos with the screen rotated 180 degrees
  Flip(SCREEN_R180);
  randomHello();

  // Print random hellos with the screen rotated 270 degrees
  Flip(SCREEN_R270);
  randomHello();

  // Print random circles
  Flip(SCREEN_NORMAL);

  for(byte i = 0; i < 10; i++)
    randomCircles();

  // Print random rectangles

  for(byte i = 0; i < 25; i++)
    randomRectangles();

  // Print random bitmaps

  for(byte i = 0; i < 3; i++)
    randomBitmap();

  // Print random lines

  for(int i = 0; i < 5; i++)
    randomLines();

  // Display a series of patterns

  Patterns();

  delay(1000);
  }
  */

}
