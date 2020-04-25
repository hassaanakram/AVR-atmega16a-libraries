#ifndef SPI_H
#define SPI_H

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
  MASTER MODULE FUNCTIONS
*/
extern void spiMaster_INIT(unsigned char/*SPIE*/, unsigned char /*DORD*/, unsigned char /*CPOL*/, unsigned char /*CPHA*/, unsigned char, unsigned char /*SPR1:0*/);
extern void spiMaster_TRANSMIT(unsigned char);
extern unsigned char spiMaster_RECEIVE();
extern void spiMaster_DOUBLESPEED();

/*
  SLAVE MODULE FUNCTIONS
*/
extern void spiSlave_INIT(unsigned char/*SPIE*/, unsigned char /*DORD*/, unsigned char /*CPOL*/, unsigned char /*CPHA*/, unsigned char, unsigned char /*SPR1:0*/);
extern void spiSlave_TRANSMIT(unsigned char);
extern unsigned char spiSlave_RECEIVE();

#endif