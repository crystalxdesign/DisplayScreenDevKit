/*
 * Project for Raspberry Pi Pico
 *
 * @version     1.0.0
 * @author      <YOU>
 * @copyright   2024
 * @licence     MIT
 *
 */
#ifndef _Project_MAIN_HEADER_
#define _Project_MAIN_HEADER_

/*
 * C++ HEADERS
 */
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <cstring>

/*
 * PICO HEADERS
 */
#include "pico/stdlib.h"
#include "pico/time.h"
#include "pico/binary_info.h"
#include "hardware/gpio.h"
#include "hardware/spi.h"
#include "hardware/uart.h"

#ifdef __cplusplus
extern "C" {
#endif
#define SPI_PORT spi0

#ifdef RP2030_Zero
// CE -> SPI0 CSn
#define CE_PIN   5
// CLK -> SPI0 SCK
#define CLK_PIN  6
//DIN -> SPI0 TX
#define DIN_PIN 7
// DC -> GP12
#define DC_PIN   12
// RST -> GP13
#define RST_PIN  13
#else
// CE (SPI0 CSn)
#define CE_PIN   17
// CLK (SPI0 SCK)
#define CLK_PIN  18
// DIN (SPI0 TX)
#define DIN_PIN 19
// DC -> GP20
#define DC_PIN   20
// RST -> GP21
#define RST_PIN  21
#endif

#include "HCDisplay.h"
#include "demos.h"
/*
 * Usual header code here
 */

#ifdef __cplusplus
}
#endif

#endif // _Project_MAIN_HEADER_
