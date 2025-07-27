#ifndef arduino_h
#define arduino_h
#include "main.h"
#define PROGMEM
#define boolean bool
#define delay sleep_ms
#define byte uint8_t
#define OUTPUT 1
#define INPUT 0
#define HIGH 1
#define LOW 0
#define digitalWrite gpio_put

#define pgm_read_byte_near(addr) (*(const unsigned char *)(addr))
#define pgm_read_word_near(addr) (*(const unsigned short *)(addr))

#endif