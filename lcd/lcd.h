/*
 *	lcd.h
 *  Author: Muhammad Hassaan
 *  lcd.h contains the definition of lcd class which is a handler for easier incorporation of
 *  LCD displays in AVR/ATMEGA16A projects.
 
 *  Questions: 1) Should i write individual methods for each function of the lcd or simply create one/two functions
 *  and pass command as argument etc?
 *
 */ 
#include <avr/io.h>

typedef volatile uint8_t reg8;

#ifndef LCD_H_
#define LCD_H_
class lcd
{
private:
	/*char cmdReg;
	char dataReg;*/
	/*Pointers to the ports*/
	reg8 *busPort;
	reg8 *modePort;
	/*E, RS, R/W" Pins*/
	char enable;
	char RS;
	char RW;
	
public:
	/*Constructor*/
	lcd(reg8*/*busPort*/, reg8*/*modePort*/, char, char, char /*E, RS, RW (pin numbers)*/);
	
	/*Methods:
	  Commands*/
	void clearDisplay();
	void retHome();
	void decCursor();
	void incCursor();
	void dispRight();
	void dispLeft();
	void dispcurOff();
	void dispOff();
	void curOff();
	void curBlink();
	void curLeft();
	void curRight();
	void entireDispRight();
	void entireDispLeft();
	void toFirstLine();
	void toSecLine();
	void eightBitMode();
	void fourBitMode();
	void gotoxy(const unsigned char/*x*/, const unsigned char /*y*/);
	void writeCommand(const unsigned char /*cmd*/);
	//Should i do 2 functions or 1 but with two different modes?
	void initLcd8();
	void initLcd4();
	/*Data Write*/
	void writeData(char /*char*/);
	void writeString(const char*);
};




#endif /* LCD_H_ */