#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

#define SS		2
#define SCK		5

#define BYTE		8

static uint8_t receiveSPIMaster(void);

void initSPIMaster(void)
{
	DDRB |= _BV(SCK) | _BV(SS);
	PORTB |= _BV(SS);						/*pull high to idle if SS is output*/
	
	/*spi enable
	master select
	clock phase (trailing edge sample)
	16 prescaler*/
	SPCR |= _BV(SPE) | _BV(MSTR) | _BV(CPHA) | _BV(SPR0);
}

uint16_t readDataSPIMaster(void)
{
	uint16_t data = 0;
	
	PORTB &= ~_BV(SS);						/*select slave by pulling low*/
	data = (receiveSPIMaster() << BYTE) | receiveSPIMaster();
	PORTB |= _BV(SS);						/*release slave by pulling high*/
	
	return data;
}

static uint8_t receiveSPIMaster(void)
{
	SPDR = 0x00;							/*fill buffer*/
	loop_until_bit_is_set(SPSR, SPIF);
	
	return SPDR;
}
