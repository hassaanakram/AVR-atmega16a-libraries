#ifndef SSEG_H_
#define SSEG_H_
#include <avr/io.h>
typedef volatile uint8_t reg8;

class SSEG
{
private:
		reg8 *port;
		reg8 *ddr;
public:
	SSEG(reg8*/*port*/, reg8*/*ddr*/);
	/*Methods*/
	void writeData(const char&/*data*/);
};
#endif /* SSEG_H_ */