#ifndef SPI_H
#define SPI_H
#include <avr/io.h>
/*
  SPI.H HEADER CONTAINING EXTERN DEFINITIONS FOR SPI TRANSMISSION IN ATMEL ATMEGA16A
  AUTHOR: MUHAMMAD HASSAAN - 24-APRIL-2020
*/

/*
  PIN LOCATIONS
*/

#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7

/*
  MASTER INIT
*/
extern void spiMaster_INIT (unsigned char , unsigned char , unsigned char , unsigned char , unsigned char , unsigned char );

/*DATA MOVEMENT FUNCTIONS*/
extern unsigned char spi_TRANSCEIVER(unsigned char);
//extern void spiMaster_DOUBLESPEED();

/*
  SLAVE MODULE FUNCTIONS
*/
extern void spiSlave_INIT();

#endif