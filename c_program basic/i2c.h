/*----------------------------------------------------------------------------------
*					 	       		 i2c.h		
*	Header file for i2c_devices
*	Serial Clock = 100Khz
*
----------------------------------------------------------------------------------*/

//#define PCF8574AP
#define PCF8574P

/* I2C Slave Settings */
#define EEPROM			0x50		// 0b1010000 - 7 bit slave address (B0=0)
#define RTC				0x68		// 0b1101000 - 7 bit slave address (Factory Set)

/*  PCF8574AP  */
#ifdef PCF8574AP
#define IOEXP_LCD_DATA	0x3F		// 0b0111111 - 7 bit slave address (A0=A1=A2=1)//PCF8574 - 0100111
#define IOEXP_LCD_CTRL	0x38		// 0b0111000 - 7 bit slave address (A0=A1=A2=0)//PCF8574 - 0100000
#endif

/*  PCF8574P  */
#ifdef PCF8574P
#define IOEXP_LCD_DATA	0x27		// 0b0100111 - 7 bit slave address (A0=A1=A2=1)//PCF8574 - 0100111
#define IOEXP_LCD_CTRL	0x20		// 0b0100000 - 7 bit slave address (A0=A1=A2=0)//PCF8574 - 0100000
#endif

#define SRF02			0x70		// 0b1110000 - 7 bit slave address
#define LIS3LV02DQ		0x1D		// 0b0011101 - 7 bit slave address (Factory Set)
#define LIS302DL		0x1C		// 0b001110x - 7 bit slave address (LSB = 0)
#define MCP9800			0x48		// 0b1001000 - 7 bit slave address (Factory Set)


#define SLAVE_WR(val)	(((val) << 1))		// Slave Write operation command word
#define SLAVE_RD(val)   (((val) << 1) | 1)	// Slave Read operation command word


/* I2C Port Settings */
#define SCL_DIR TRISC3
#define SDA_DIR TRISC4
#define INPUT	1					// Set PORT pin as input
#define CLEAR	0					// Clear flag status
#define SET		1					// Set bit status
#define NACK	1					// No Acknowledge (SDA High)
#define ACK		0					// Acknowledge (SDA Low)


/* I2C Register Settings */
#define I2C_MASTER_MODE 0x28	// I2C Master mode, clock = FOSC/(4 * (SSPADD + 1))
#define SMP_DISABLE 0x80		// Slew rate control disabled for standard speed mode (100 kHz and 1 MHz)
#define SMP_ENABLE 0x00			// Slew rate control enabled for high speed mode ( 400 khz)
#define SEN_DISABLE 0x00		// Clock stretching is enabled for slave transmit only


/* I2C Baud Settings */
#define FOSC 16000 				// Oscillator freq in Khz
#define BAUD 100				// Baud rate of transmission in Khz

//#define I2C_SLAVE_MODE 0x36	// I2C Slave mode, 7-bit address
//#define BAUD 32				// Baud rate of transmission in Khz
//#define CLEAR 0				// Clear Interrupt Flag status

/*-- Preprocessor for LCD --*/
#define OUTPUT 0x00				// Set PORT Pins as output
#define ALL_ANALOG 0x06			// All pins of PORTA and PORTE are digital I/O

#define wait_mssp()		while(!SSPIF);SSPIF=CLEAR

						//Wait for I2C module to complete it's last operation
						//Clear MSSP flag bit



/*----------------------------------------------------------------------------------*/
