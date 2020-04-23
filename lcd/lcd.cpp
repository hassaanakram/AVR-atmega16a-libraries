/*
 * lcd.cpp
 *lcd.h implementation file
 * 
 */ 

#include "lcd.h"
#include <util/delay.h>
#define F_CPU 1000000UL //Clock frequency
typedef volatile uint8_t reg;

/*Delay wrappers*/

void delay_ms(uint16_t ms)
{
	uint16_t i = 0;
	
	for(;i < ms; i++)
		_delay_ms(1);
		
	return;
}
void delay_us(uint16_t us)
{
	uint16_t i = 0;
	
	for(;i < us; i++)
	_delay_us(1);
	
	return;
}
/*Constructor*/
lcd::lcd(reg8 *bus, reg8 *mode, char rs, char rw, char e)
{
	/*Ports setup*/ 
	busPort = bus;
	modePort = mode;
	enable = e;
	RS = rs;
	RW = rw;
	/*DDRx and PINx*/
	
	/*Again, here should i declare new pointers to the ddrx and pinx or should i continue
	using pointer arithmetic throughout?*/
	
	reg *busDDR = busPort - 1;
	//reg *busPIN = busPort + 1;
	reg *modeDDR = modePort - 1;
	//reg *modePIN = modePort + 1;
	
	*(busDDR) = 0xFF;
	/*Mode port bit setting*/
	*(modeDDR) = (1 << enable) | (1 << RS) | (1 << RW);
	/*Enabler = 0*/
	*modePort = 0 << enable; 	
	
	delay_ms(15);
	return;
}

/*Methods*/
void lcd::clearDisplay()
{
	*(busPort) = 0x01;
	*(modePort) = (1 << enable) | (0 << RS) | (0 << RW);
	delay_us(0.5);
	*(modePort) = (0 << enable) | (0 << RS) | (0 << RW);
	
	delay_ms(2);
	return;
}
void lcd::retHome()
{
	*(busPort) = 0x02;
	*(modePort) = (1 << enable) | (0 << RS) | (0 << RW);
	delay_us(0.5);
	*(modePort) = (0 << enable) | (0 << RS) | (0 << RW);
	
	delay_ms(2);
	return;
}
void lcd::decCursor()
{
	*(busPort) = 0x04;
	*(modePort) = (1 << enable) | (0 << RS) | (0 << RW);
	delay_us(0.5);
	*(modePort) = (0 << enable) | (0 << RS) | (0 << RW);
	
	delay_us(100);
	return;
}
void lcd::incCursor()
{
	*(busPort) = 0x06;
	*(modePort) = (1 << enable) | (0 << RS) | (0 << RW);
	delay_us(0.5);
	*(modePort) = (0 << enable) | (0 << RS) | (0 << RW);
	
	delay_us(100);
	return;
}
void lcd::dispRight()
{
	*(busPort) = 0x05;
	*(modePort) = (1 << enable) | (0 << RS) | (0 << RW);
	delay_us(0.5);
	*(modePort) = (0 << enable) | (0 << RS) | (0 << RW);
	
	delay_us(100);
	return;
}
void lcd::dispLeft()
{
	*(busPort) = 0x07;
	*(modePort) = (1 << enable) | (0 << RS) | (0 << RW);
	delay_us(0.5);
	*(modePort) = (0 << enable) | (0 << RS) | (0 << RW);
	
	delay_us(100);
	return;
}
void lcd::dispcurOff()
{
	*(busPort) = 0x08;
	*(modePort) = (1 << enable) | (0 << RS) | (0 << RW);
	delay_us(0.5);
	*(modePort) = (0 << enable) | (0 << RS) | (0 << RW);
	
	delay_us(100);
	return;
}
void lcd::dispOff()
{
	*(busPort) = 0x0A;
	*(modePort) = (1 << enable) | (0 << RS) | (0 << RW);
	delay_us(0.5);
	*(modePort) = (0 << enable) | (0 << RS) | (0 << RW);
	
	delay_us(100);
	return;
}
void lcd::curOff()
{
	*(busPort) = 0x0C;
	*(modePort) = (1 << enable) | (0 << RS) | (0 << RW);
	delay_us(0.5);
	*(modePort) = (0 << enable) | (0 << RS) | (0 << RW);
	
	delay_us(100);
	return;
}
void lcd::curBlink()
{
	*(busPort) = 0x0E;
	*(modePort) = (1 << enable) | (0 << RS) | (0 << RW);
	delay_us(0.5);
	*(modePort) = (0 << enable) | (0 << RS) | (0 << RW);
	
	delay_us(100);
	return;
}
void lcd::curLeft()
{
	*(busPort) = 0x10;
	*(modePort) = (1 << enable) | (0 << RS) | (0 << RW);
	delay_us(0.5);
	*(modePort) = (0 << enable) | (0 << RS) | (0 << RW);
	
	delay_us(100);
	return;
}
void lcd::curRight()
{
	*(busPort) = 0x14;
	*(modePort) = (1 << enable) | (0 << RS) | (0 << RW);
	delay_us(0.5);
	*(modePort) = (0 << enable) | (0 << RS) | (0 << RW);
	
	delay_us(100);
	return;
}
void lcd::entireDispLeft()
{
	*(busPort) = 0x18;
	*(modePort) = (1 << enable) | (0 << RS) | (0 << RW);
	delay_us(0.5);
	*(modePort) = (0 << enable) | (0 << RS) | (0 << RW);
	
	delay_us(100);
	return;
}
void lcd::entireDispRight()
{
	*(busPort) = 0x1C;
	*(modePort) = (1 << enable) | (0 << RS) | (0 << RW);
	delay_us(0.5);
	*(modePort) = (0 << enable) | (0 << RS) | (0 << RW);
	
	delay_us(100);
	return;
}
void lcd::toFirstLine()
{
	*(busPort) = 0x80;
	*(modePort) = (1 << enable) | (0 << RS) | (0 << RW);
	delay_us(0.5);
	*(modePort) = (0 << enable) | (0 << RS) | (0 << RW);
	
	delay_us(100);
	return;
}
void lcd::toSecLine()
{
	*(busPort) = 0xC0;
	*(modePort) = (1 << enable) | (0 << RS) | (0 << RW);
	delay_us(0.5);
	*(modePort) = (0 << enable) | (0 << RS) | (0 << RW);
	
	delay_us(100);
	return;
}
void lcd::fourBitMode()
{
	*(busPort) = 0x28;
	*(modePort) = (1 << enable) | (0 << RS) | (0 << RW);
	delay_us(0.5);
	*(modePort) = (0 << enable) | (0 << RS) | (0 << RW);
	
	delay_us(100);
	return;
}
void lcd::eightBitMode()
{
	*(busPort) = 0x38;
	*(modePort) = (1 << enable) | (0 << RS) | (0 << RW);
	delay_us(0.5);
	*(modePort) = (0 << enable) | (0 << RS) | (0 << RW);
	
	delay_us(100);
	return;
}
void lcd::initLcd8()
{
	eightBitMode();
	curBlink();
	clearDisplay();
	
	return;
}
void lcd::initLcd4()
{
	fourBitMode();
	curBlink();
	clearDisplay();
	
	return;	
}

void lcd::writeData(char data)
{
	//char i = 0;
	
	//while(*(data + i) != '\0')
	//{
		*(busPort) = static_cast<reg>(data);
		*(modePort) = (1 << enable) | (1 << RS) | (0 << RW);
		delay_us(0.5);
		*(modePort) = (0 << enable) | (1 << RS) | (0 << RW);
	    delay_us(100);
		
		//i++; 
	//}
	
	return;
}
void lcd::writeString(const char* data)
{
	char i = 0;
	
	while(*(data + i) != '\0')
	{
		*(busPort) = static_cast<reg>(*data);
		*(modePort) = (1 << enable) | (1 << RS) | (0 << RW);
		delay_us(0.5);
		*(modePort) = (0 << enable) | (1 << RS) | (0 << RW);
		delay_us(100);
	
		i++;
	}
	
	return;
}
void lcd::writeCommand(const unsigned char cmd)
{
	*(busPort) = cmd;
	*(modePort) = (1 << enable) | (0 << RS) | (0 << RW);
	delay_us(0.5);
	*(modePort) = (0 << enable) | (0 << RS) | (0 << RW);
	
	delay_us(100);
	return;
}
void lcd::gotoxy(const unsigned char x, const unsigned char y)
{
	unsigned char firstColAddr[] = {0x80,0xC0}; //2x16LCD
	
	writeCommand(firstColAddr[y-1] + x -1); //This is effectively line number + x-offset
	
	return;
}