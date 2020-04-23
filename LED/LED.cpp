#include "LED.h"
typedef volatile uint8_t reg8;

LED::LED(reg8 *p, reg8 *d, char pn)
{
	port = p;
	ddr = d;
	pinNumber = pn;
	
	/*Setup*/
	*(ddr) = 1 << pinNumber;
}
/*Method(s)*/
void LED::setState(char state)
{
	*(port) = state << pinNumber;
	
	return;
}