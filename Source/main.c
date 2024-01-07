#include "seg7_display.h"
#include "spi_master.h"
#include "timer0.h"

int main(void)
{
	initDisplay();
	initSPIMaster();
	
	initTimer();
	resetTimer();
	
	while(1)
	{
		
	}
}
