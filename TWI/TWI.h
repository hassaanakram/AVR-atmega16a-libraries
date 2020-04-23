/*TWI: EXTERN FUNCTION DEFINITIONS FOR TWI COMMUNICATION BOTH MASTER AND SLAVE.
 */ 


#ifndef TWI_H_
#define TWI_H_
#include <avr/io.h>

/*FUNCTION PROTOTYPES FOR MASTER COMMUNICATION MODULE*/
extern void i2cMaster_INIT();
extern void i2cMaster_TRANSMIT(unsigned char/*data*/);
//extern unsigned char i2cMaster_RECEIVE();
extern void i2cMaster_START();
extern void i2cMaster_STOP();
/*FUNCTION PROTOTYPES FOR SLAVE COMMUNICATION MODULE*/
void i2cSlave_INIT(unsigned char /*addr*/);
//void i2cSlave_TRANSMIT(unsigned char/*data*/);
void i2cSlave_LISTEN();
unsigned char i2cSlave_RECEIVE();


#endif /* TWI_H_ */