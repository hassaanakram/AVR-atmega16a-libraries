#include "SSEG.h"

typedef volatile uint8_t reg8;

/*Constructor*/
SSEG::SSEG(reg8 *p, reg8 *d)
{
	port = p; ddr = d; 
	
	/*Port setup*/
	*(ddr) = 0xFF;
	*(port) = 0x00;
}
/*Methods*/
void SSEG::writeData(const char& digit)
{
	*(port) = digitVals[digit];
	
	return;
}