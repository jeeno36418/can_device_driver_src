/*--------------------------------------------------------------------------------------
*
*									i2c_mems_driver_new.c
*
*	LIS302DL (3-AXIS MEMS ACCELEROMETER)
*	Manufacturer: ST Micro-Electronics
*--------------------------------------------------------------------------------------*/
#include<pic.h>
//#include "delay.c"
#include "lis302dl.h"

#ifndef _I2C
#define _I2C
#include "i2c.c"
#endif

/*--------------------------------------------*/

void i2c_mems_byte_write(unsigned char mems_byte_addr,unsigned char mems_data);
unsigned char i2c_mems_byte_read(unsigned char mems_byte_addr);
void i2c_mems_block_read();
void i2c_mems_init(unsigned char mode);
void clear_mems_sensor_latch();
void reset_to_current_position();

/*--------------------------------------------*/

char mems_result[5];

/*--------------------------------------------*/

//void main(){}

/*--------------------------------------------*/

void
i2c_mems_byte_write(unsigned char mems_byte_addr,unsigned char mems_byte){

	i2c_start();								// Send start command
	i2c_byte_write(SLAVE_WR(LIS302DL));			// Send control byte for write operation
	i2c_byte_write(mems_byte_addr);				// Send register address 
	i2c_byte_write(mems_byte);					// Send data byte
	i2c_stop();									// Send stop command
}
/*--------------------------------------------*/

unsigned char
i2c_mems_byte_read(unsigned char mems_byte_addr){
	unsigned char mems_byte;

	i2c_start();								// Send start command
	i2c_byte_write(SLAVE_WR(LIS302DL));			// Send control byte for write operation	
	i2c_byte_write(mems_byte_addr);				// Send register address
	i2c_repeated_start();						// Send repeated start
	i2c_byte_write(SLAVE_RD(LIS302DL));			// Send control byte for read operation
	mems_byte = i2c_byte_read();				// read data from slave
	i2c_nack();									// Send no acknowledge to Slave
	i2c_stop();									// Send stop command
	return mems_byte;
}
/*--------------------------------------------*/

void i2c_mems_block_read(){
	unsigned char *mems_ptr = mems_result;
	unsigned char cnt;

	cnt = RESULT_SIZE;
	while(!(i2c_mems_byte_read(STATUS_REG)&0x08));
	
	i2c_start();									// Send start command
	i2c_byte_write(SLAVE_WR(LIS302DL));				// Send control byte for write operation
	i2c_byte_write(MULTIBYTE(OUT_X));				// Send starting address for multibyte access
	i2c_repeated_start();							// Send repeated start
	i2c_byte_write(SLAVE_RD(LIS302DL));				// Send control byte for read operation

	while(cnt-1){
		*mems_ptr = i2c_byte_read();				// Read data from slave
		i2c_ack();
		mems_ptr++;
		cnt--;
	}
	*mems_ptr = i2c_byte_read();					// Read last data byte from slave
	i2c_nack();										// Send no acknowledge to Slave
	i2c_stop();										// Send stop command
}

/*--------------------------------------------*/

void i2c_mems_init(unsigned char mode){

	switch(mode){
		case LOW_G:
					i2c_mems_byte_write(CTRL_REG1,0x47);		// Turn on the sensor and set ODR=100 Hz
					DelayMs(100);
					break;
					
		case HIGH_G:
					i2c_mems_byte_write(CTRL_REG1,0xE7);		// Turn on the sensor, ODR=400 Hz, FS=8g
					DelayMs(100);
					break;

		case WAKE_UP:
					i2c_mems_byte_write(CTRL_REG1,0xC7);		// Turn on the sensor and set ODR=400 Hz	
					i2c_mems_byte_write(CTRL_REG2,0x08);		// High Pass filter enabled on FF_WU2, fcutoff=8Hz
					i2c_mems_byte_write(CTRL_REG3,0x10);		// FF_WU2 interrupt sent to INT2 pin
					i2c_mems_byte_write(FF_WU_THS_2,0x86);		// Set wake-up threshold (thr*18) mg
					i2c_mems_byte_write(FF_WU_DURATION_2,0x00);	// No filtering/confirmation on the event
					i2c_mems_byte_read(HP_FILTER_RESET);		// Set reference acceleration/tilt value)
					i2c_mems_byte_write(FF_WU_CFG_2,0x6A);		// Configure desired wake-up event
					break;
					
		case FREE_FALL:
					i2c_mems_byte_write(CTRL_REG1,0x47);
					i2c_mems_byte_write(CTRL_REG2,0x00);
					i2c_mems_byte_write(CTRL_REG3,0x10);
					i2c_mems_byte_write(FF_WU_THS_2,0x14);		// Set free-fall threshold (thr*18) mg
					i2c_mems_byte_write(FF_WU_DURATION_2,0x00);
					i2c_mems_byte_write(FF_WU_CFG_2,0xD5);
					break;					

		case PWR_DOWN:	
					i2c_mems_byte_write(CTRL_REG1,0x07);		// Turn off the sensor (power down mode)
					break;						
					
		default: break;
	}	
}

/*--------------------------------------------*/

void clear_mems_sensor_latch(){
	i2c_mems_byte_read(FF_WU_SRC_2);		// Clear interrupt request
}
/*--------------------------------------------*/

void reset_to_current_position(){
	i2c_mems_byte_read(HP_FILTER_RESET);
}
/*--------------------------------------------*/
