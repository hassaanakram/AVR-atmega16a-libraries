#include "SPI.h"

/*FUNCTION IMPLEMENTATIONS*/

void spiMaster_INIT (unsigned char spie, unsigned char dord, unsigned char cpol, unsigned char cpha, unsigned char spr1, unsigned char spr0)
{
	/*spiMaster_INIT INITIALIZES SPI MASTER MODE WITH SPRC SETTINGS AS PASSED IN THE ARGUMENTS*/
	
	DDRB |= (1<<MOSI) | (1<<SCK) | (1<<SS);
	
	SPCR = (1<<SPE)|(1<<MSTR) | (spie << SPIE) | (dord << DORD) | (cpol << CPOL) | (cpha << CPHA) | (spr1 << SPR1)  | (spr0 << SPR0);
}

void spiSlave_INIT(void)
{
	/*SLAVE INTIALIZATION ROUTINE*/
	
	DDRB |= (1<<MISO); // Set MISO as an Output Pin
	SPCR = (1<<SPE); // Enable SPI as a Slave Device
}
unsigned char spi_TRANSCEIVER(unsigned char data)
{
	/*PUSHES THE INPUT DATA TO SPDR REGISTER AND WAITS FOR IT'S TRANSMISSION TO FINISH. IF SOMETHING IS RECEIVED, IT IS FETCHED AND RETURNED*/
	
	SPDR = data;
	
	while (! (SPSR & (1 << SPIF)));
	
	return SPDR;
}
