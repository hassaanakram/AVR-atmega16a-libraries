#ifndef SSEG_H_
#define SSEG_H_
#include <avr/io.h>
typedef volatile uint8_t reg8;

class SSEG
{
private:
		reg8 *port;
		reg8 *ddr;
		//Array holding data for CA SSG
		char digitVals[10] = {0x01,0x4F,0x12,0x06,0x4C,
														0x24,0x20,0x0F,0x00,0x0C};
public:
	SSEG(reg8*/*port*/, reg8*/*ddr*/);
	/*Methods*/
	void writeData(const char&/*data*/);
};
#endif /* SSEG_H_ */