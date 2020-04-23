#ifndef LED_H_
#define LED_H_
#include <avr/io.h>
typedef volatile uint8_t reg8;

class LED
{
private:
	reg8 *ddr;
	reg8 *port;
	char pinNumber;
public:
	LED(reg8*/*port*/, reg8*/*ddr*/, char/*pin number*/);
	/*Methods*/
	void setState(char/*state*/);
};
#endif /* LED_H_ */