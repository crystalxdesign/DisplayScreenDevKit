#ifndef _Demos_HEADER_
#define _Demos_HEADER_
void ScreenInit(void);
void PrintCentre(char *, uint8_t , uint8_t);
void Intro(void);
void ScrollInABox(void);
void randomHello(void);
void randomCircles(void);
void randomRectangles(void);
void randomBitmap(void);
void randomLines(void);
void Patterns(void);
void Clear(void);
void Contrast(uint8_t);
uint16_t ResX();
uint16_t ResY();
void Flip(uint8_t);
void graph(void);
#endif