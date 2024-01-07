#ifndef SEG7_DISPLAY_H
#define SEG7_DISPLAY_H

#include <stdint.h>

void initDisplay(void);
void fillDigits(uint8_t [], const uint8_t, uint16_t);
void switchDigits(const uint8_t);
void switchSegments(const uint8_t [], const uint8_t);

#endif