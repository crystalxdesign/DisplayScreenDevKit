#include "HCDisplay.h"
#include "demos.h"
#include <math.h>

HCDisplay HCDisplay;    // Creates an instance of the HCDisplay library
uint16_t resX;
uint16_t resY;

uint8_t _random(uint8_t min, uint8_t max){
    int retval = rand() % max + min;
    return (uint8_t)retval;
}

/*Example bitmap */
const PROGMEM uint8_t Tiny_Resistor_Bitmap[] =
{
  0x00, 0x3C, 0x00, 0x00, 0x7E, 0x00, 0x00, 0xE7, 0x00, 0x00, 0xC3, 0x00, 0x01, 0xC3, 0x80, 0x01, 0xC3, 0x80, 0x00, 0xC3, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x78, 0x00, 0x01, 0xF0, 0x00, 0x07, 0xC0, 0x00, 0x1F, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x07, 0xC0, 0x00, 0x01, 0xF0, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x07, 0xC0, 0x00, 0x01, 0xF0, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x3E, 0x00, 0x00, 0xFC, 0x00, 0x03, 0xF0, 0x00, 0x0F, 0xC0, 0x00, 0x3F, 0x00, 0x00, 0xFC, 0x00, 0x03, 0xF0, 0x00, 0x0F, 0xC0, 0x00, 0x3F, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x0F, 0x80, 0x00, 0x03, 0xE0, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x0F, 0x80, 0x00, 0x03, 0xE0, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x3E, 0x00, 0x00, 0xF8, 0x00, 0x03, 0xE0, 0x00, 0x0F, 0x80, 0x00, 0x3E, 0x00, 0x00, 0xF8, 0x00, 0x03, 0xE0, 0x00, 0x0F, 0x80, 0x00, 0x3E, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x0F, 0x80, 0x00, 0x03, 0xE0, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x0F, 0x80, 0x00, 0x03, 0xE0, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x3E, 0x00, 0x00, 0xF8, 0x00, 0x03, 0xE0, 0x00, 0x0F, 0x80, 0x00, 0x3E, 0x00, 0x00, 0xF8, 0x00, 0x03, 0xE0, 0x00, 0x0F, 0x80, 0x00, 0x3E, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x0F, 0xC0, 0x00, 0x03, 0xF0, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x0F, 0xC0, 0x00, 0x03, 0xF0, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x7C, 0x00, 0x01, 0xF0, 0x00, 0x07, 0xC0, 0x00, 0x1F, 0x00, 0x00, 0x7C, 0x00, 0x01, 0xF0, 0x00, 0x07, 0xC0, 0x00, 0x1F, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x07, 0xC0, 0x00, 0x01, 0xF0, 0x00, 0x00, 0x78, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x7E, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xC3, 0x00, 0x01, 0xC3, 0x80, 0x01, 0xC3, 0x80, 0x00, 0xC3, 0x00, 0x00, 0xE7, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x3C, 0x00, 
};

void ScreenInit(){
    HCDisplay.Init(DIN_PIN, CLK_PIN, CE_PIN, DC_PIN, RST_PIN);
    resX = HCDisplay.ResX();
    resY = HCDisplay.ResY();
}

void Contrast(uint8_t cont){
    HCDisplay.Contrast(cont);
}

void Clear(){
    HCDisplay.Clear();
}

uint16_t ResX(){
    return HCDisplay.ResX();
}

uint16_t ResY(){
    return HCDisplay.ResY();
}

void Flip(uint8_t screenMode){
    HCDisplay.Flip(screenMode);
}

void PrintCentre(char *string, uint8_t Scale, uint8_t y)
{
  HCDisplay.ScaleXY(Scale, Scale);
  HCDisplay.Pos((resX / 2) - ((strlen(string) * (8* Scale)) / 2), y); 
  HCDisplay.Print(string);
}

void Intro()
{
  PrintCentre((char *)"Hobby Components", 1, (resY / 2) - 30);
  HCDisplay.SetFG(0); HCDisplay.SetBG(1);
  PrintCentre((char *)"HCDisplay", 1,  (resY / 2) - 20);
  HCDisplay.SetFG(1); HCDisplay.SetBG(0);
  PrintCentre((char *)"Library Demo", 1,  (resY / 2) - 10);

  HCDisplay.SetFont(LCDLarge_24ptFont);
  
  for(int8_t i = 10; i >= 0; i--)
  {
    HCDisplay.Pos(60, 30);
    HCDisplay.Print(i, 0);
    delay(500);
    HCDisplay.SetFG(0);
    HCDisplay.Pos(60, 30);
    HCDisplay.Print(i, 0);
    HCDisplay.SetFG(1);
  }

  HCDisplay.SetFont(SystemFont);

  HCDisplay.Clear();
  
  for(byte Scale = 1; Scale < 8; Scale++)
  {
    PrintCentre((char *)"Hello!", Scale, resY / 2 - (Scale * 8 / 2));
    delay(200); 
  }

  delay(2000);
}

void ScrollInABox()
{
  //HCDisplay.SetFont(SystemFont);
  HCDisplay.SetFont(MedProp_12ptFont);
  HCDisplay.ScaleXY(1, 2);

  HCDisplay.AutoRefresh(OFF);
  
  for(int x = 90; x > -360; x -= 4 )
  {
    HCDisplay.Rect(20, 10, 107, 53, FILLED);

    HCDisplay.Pos(x, 16); 
    HCDisplay.DrawMode(DRAWMODE_AND_INV);
    HCDisplay.Print("HCDisplay - ST7565 LCD (HCMODU0245 & 246) ", false);
    HCDisplay.Refresh();
    HCDisplay.Clear();
    HCDisplay.DrawMode(DRAWMODE_NORMAL);
    delay(200);
  }

  HCDisplay.SetFont(SystemFont);
  HCDisplay.AutoRefresh(ON);
}

void randomHello()
{
  resX = HCDisplay.ResX();
  resY = HCDisplay.ResY();

  HCDisplay.Clear();
  
  for(int i = 0; i < 100; i++)
  {
    //Scaling the random number helps make it a bit more random
    byte FG = _random(0,255); 
    FG >>= 7;

    HCDisplay.Pos(_random(-10, resX), _random(-10, resY));
    HCDisplay.ScaleXY(_random(1,4), _random(1,4));
    HCDisplay.SetFG(FG);
    HCDisplay.SetBG(1 - FG);
    HCDisplay.Print("Hello!"); 
    delay(50);
  }

  HCDisplay.SetFG(1);
  HCDisplay.SetBG(0);
  HCDisplay.ScaleXY(1, 1);
}

void randomCircles()
{
  HCDisplay.Clear();
  HCDisplay.DrawMode(DRAWMODE_XOR);
  
  for(int i = 0; i < 10; i++)
  {
    byte Radius = _random(1, 40);
    byte Width = _random(1, 20);

    HCDisplay.Circle(_random(0, resX), _random(0, resY), Radius, OUTLINE, Width); 
    delay(50);
  }
  
  HCDisplay.DrawMode(DRAWMODE_NORMAL);
}

void randomRectangles()
{
  HCDisplay.Clear();
  HCDisplay.DrawMode(DRAWMODE_XOR);
  
  for(int i = 0; i < 10; i++)
  { 
    byte Width = _random(1, 5);
    boolean Mode;

    if(_random(0,10) >= 5)
      Mode = FILLED;
    else
      Mode = OUTLINE;

    HCDisplay.Rect(_random(0, resX), _random(0, resY), _random(0, resX), _random(0, resY), Mode, Width); 
    delay(50);
  }

  HCDisplay.DrawMode(DRAWMODE_NORMAL);
}

void randomBitmap()
{
  HCDisplay.Clear();
  HCDisplay.DrawMode(DRAWMODE_XOR);
  
  for(int i = 0; i < 20; i++)
  { 
    HCDisplay.Pos(_random(-100, resX), _random(-100, resY));
    HCDisplay.BWBitmap(127, 3, Tiny_Resistor_Bitmap, false);
    delay(50);
  }

  HCDisplay.DrawMode(DRAWMODE_NORMAL);
}

void randomLines()
{
  HCDisplay.Clear();
  
  for(byte i = 0; i < 20; i++)
    HCDisplay.Line(_random(0, resX), _random(0, resY), _random(0, resX), _random(0, resY)); 
    delay(50);
}

void Patterns()
{
  HCDisplay.Rect(0, 0, resX - 1, resY - 1, OUTLINE, 1); 
  
  for(int x = 0; x < resX; x += 8) {
    HCDisplay.Line(x, 0, x, resY - 1);
    delay(50);
  }

  for(int y = 0; y < resY; y += 8) {
    HCDisplay.Line(0, y, resX - 1, y);
    delay(50);
  }
  delay(2000);


  HCDisplay.Clear();

  for(int x = 0; x < resX; x += 8) {
    HCDisplay.Line(0, 0, x, resY - 1);
    delay(50);
  }

  for(int x = 0; x < resX; x += 8){
    HCDisplay.Line(0, resY - 1, x, 0);
    delay(50);
  }

  for(int x = 0; x < resX; x += 8) {
    HCDisplay.Line(resX - 1, resY - 1, x, 0);
  }

  for(int x = 0; x < resX; x += 8) {
    HCDisplay.Line(resX - 1, 0, x, resY - 1);
    delay(50);
  }

  delay(2000);

  HCDisplay.Clear();
  for(int y = 0; y < resY + 16; y += 16)
    for(int x = 0; x < resX + 16; x += 16)
    {
      HCDisplay.SetFG(1);
      HCDisplay.Circle(x, y, 8, OUTLINE, 2); 
      delay(50);
    }
  
  delay(2000);
}

void graph(){
  HCDisplay.Clear();
  HCDisplay.Line(5, 0, 5, resY - 5);
  HCDisplay.Line(5, resY - 5, resX - 1, resY - 5);

  // Plot the sine wave
  for (int x = 5; x < resX; x++) {
      double radians = (x / (double)(resX - 6)) * 2 * M_PI;  // Map x to 0 to 2π
      double sineValue = sin(radians);  // Calculate sine value
      int y = (int)((sineValue + 1) * (resY - 6) / 2);  // Map sine value to graph height
      HCDisplay.Plot(x,y);
      delay(50);
  }
}