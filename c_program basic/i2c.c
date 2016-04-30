/*--------------------------------------------------------------------------------------
*
*									i2c.c			
*
*	MicroController	: PIC16F877A
*	Serial Clock	: 100 Khz
*--------------------------------------------------------------------------------------*/

#include<pic.h>
#include "i2c.h"
//#include "delay.c"
//#include "lcd_driver_4bit.c"

/*--------------------------------------------*/

//__CONFIG(HS & WRTEN & WP3 & WDTDIS & PWRTEN & BORDIS & LVPDIS & DEBUGDIS & UNPROTECT & DUNPROT);

/*--------------------------------------------*/

void setup_i2c_port(void);
void setup_i2c_master(void);
void i2c_byte_write(unsigned char i2c_byte);
unsigned char i2c_byte_read(void);
//void wait_mssp();
void i2c_start(void);
void i2c_stop(void);
void i2c_nack(void);
void i2c_ack(void);
void i2c_repeated_start(void);

/*--------------------------------------------*/

//void main(){}
//void main(){
//	setup_lcd_port();
//	setup_i2c_port();
//	setup_i2c_master();
//
//	DelayMs(100);
//	lcd_init();
//	lcd_puts("i2c");
//	DelayMs(250);DelayMs(250);DelayMs(250);	
//	i2c_start();									// Send start command
//	i2c_byte_write(SLAVE_WR(EEPROM));				// Send control byte
//	i2c_byte_write(0x00);							// Send address byte where data will be stored
//	i2c_byte_write(0x00);							// Send data byte to be stored
//	i2c_byte_write(0x01);							// Send data byte to be stored	
//	i2c_stop();										// Send stop command
//	DelayMs(250);
//	lcd_puts("  OK");
//	while(1);	
//}
/*--------------------------------------------*/
void i2c_byte_write(unsigned char i2c_byte){
	SSPBUF = i2c_byte;
	wait_mssp();
//	if(ACKSTAT){
//		lcd_clrscr();
//		lcd_puts("   NACK ERROR !");
//		while(2);
//	}
}
/*--------------------------------------------*/

unsigned char i2c_byte_read(void){
	unsigned char i2c_byte;
	RCEN = SET; 							// Enable Master Receive Mode, Automatically cleared after reception of 8-bit data
	wait_mssp();
	i2c_byte = SSPBUF;
	return i2c_byte;
}
/*--------------------------------------------*/

void setup_i2c_master(){
	SSPCON = I2C_MASTER_MODE;				// Mode Select	
	SSPSTAT	= SMP_DISABLE;					// Slew Rate Control 
	SSPADD = (FOSC / (4 * BAUD)) - 1;		// Configure Baud Rate (100 Khz)
}
/*--------------------------------------------*/

void i2c_start(){
	SEN = SET;		//Generate START Condition
	wait_mssp();
}
/*--------------------------------------------*/

void i2c_stop(){
	PEN = SET;		//Generate START Condition
	wait_mssp();
}
/*--------------------------------------------*/

void i2c_nack(){
	ACKDT = NACK;
	ACKEN = SET;
	wait_mssp();
}
/*--------------------------------------------*/

void i2c_ack(){
	ACKDT = ACK;
	ACKEN = SET;
	wait_mssp();
}
/*--------------------------------------------*/

void i2c_repeated_start(){
	RSEN = SET;
	wait_mssp();	 
}
/*--------------------------------------------*/

//void wait_mssp(){
//	while(!SSPIF)		//Wait for I2C module to complete it's last operation
//		continue;
//	SSPIF = CLEAR;		//Clear MSSP flag bit
//}
/*--------------------------------------------*/

void setup_i2c_port(){
	SCL_DIR = INPUT;	
	SDA_DIR = INPUT;
}
/*--------------------------------------------*/

