#include <avr/io.h>
#include <stdint.h>

#define SEG_CC_DDR		DDRD
#define SEG_CC_PORT		PORTD

#define DIG_DDR			DDRC
#define DIG_PORT		PORTC

#define DIG_1			1
#define DIG_2			2
#define DIG_3			3
#define DIG_4			4

typedef enum
{
	ZER0  = 0x3F,
	ONE   = 0x06,
	TWO   = 0x5B,
	THREE = 0x4F,
	FOUR  = 0x66,
	FIVE  = 0x6D,
	SIX   = 0x7D,
	SEVEN = 0x07,
	EIGHT = 0x7F,
	NINE  = 0x6F,
} Segments;

uint8_t digits[] = { 0, 0, 0, 0 };
const uint8_t DIGITS_SIZE = sizeof digits / sizeof digits[0];

void initDisplay(void)
{
	SEG_CC_DDR  = 0xFF;
	
	DIG_DDR |= _BV(DIG_4) | _BV(DIG_3) | _BV(DIG_2) | _BV(DIG_1);
	DIG_PORT |= _BV(DIG_4) | _BV(DIG_3) | _BV(DIG_2) | _BV(DIG_1);
}

void fillDigits(uint8_t dgts[], const uint8_t sz, uint16_t num)
{
	for(int8_t i = sz - 1; i >= 0; --i)
	{
		dgts[i] = num % 10;
		num /= 10;
	}
}

void switchDigits(const uint8_t idx)
{
	DIG_PORT |= _BV(DIG_4) | _BV(DIG_3) | _BV(DIG_2) | _BV(DIG_1);
	DIG_PORT &= ~_BV(idx + DIG_1);
}

void switchSegments(const uint8_t dgts[], const uint8_t idx)
{
	static const Segments SEGMENTS[] = { ZER0, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE };
	
	SEG_CC_PORT = SEGMENTS[dgts[idx]];
}
