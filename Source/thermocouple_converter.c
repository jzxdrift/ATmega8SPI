#include <stdint.h>

#define LSBS	3

uint16_t convertToCelsius(uint16_t data)
{
	return (data >> LSBS) * 0.25;
}
