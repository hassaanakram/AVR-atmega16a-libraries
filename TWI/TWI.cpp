/*
 * TWI.cpp: TWI.H IMPLEMENTATION
 *
 * Created: 4/23/2020 8:47:56 AM
 *  Author: moham
 */ 
#include "TWI.h"

/*FUNCTION DEFINITIONS FOR MASTER COMMUNICATION MODULE*/
void i2cMaster_INIT()
{
	TWSR = 0x00;
	TWBR = 0x47;
	TWCR = 0x04;
	
	return;
}
void i2cMaster_START()
{
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);
	while((TWCR & (1 << TWINT)) == 0);
}
void i2cMaster_STOP()
{
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}
void i2cMaster_TRANSMIT(unsigned char data)
{
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while ((TWCR & (1 << TWINT)) == 0);
}

/*FUNCTION DEFINITIONS FOR MASTER COMMUNICATION MODULE*/
void i2cSlave_INIT(unsigned char addr)
{
	TWCR = 0x04;
	TWAR = addr;
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
	return;
}
void i2cSlave_LISTEN()
{
	while ( (TWCR & (1 << TWINT)) == 0 );
}
void i2cSlave_TRANSMIT(unsigned char data)
{
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while ((TWCR & (1 << TWINT)) == 0);
}
unsigned char i2cSlave_RECEIVE()
{
	TWCR = (1 << TWINT) | (1 << TWEN);
	
	while ( (TWCR & (1 << TWINT)) == 0 );
	return (TWDR);
}