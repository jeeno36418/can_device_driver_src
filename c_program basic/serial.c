#include <pic.h>

void uart_puts(const char *);
void uart_put_array(char *);
void uart_putc(unsigned char);
void uart_init(unsigned int baud, unsigned char fosc);
unsigned char uart_getc(void);

void uart_init(unsigned int baud, unsigned char fosc)
{
	TRISC7 = TRISC6 = 1;	// Pins TRISC<7:6> have to be set for serial communication	

	/* UART Transmitter Configuration */

	baud = (unsigned char)(baud/100);
	SPBRG = ((fosc * 156)/(baud)) - 1;	// Baud rate set to desired bits per second

	BRGH = 0;					// Setting low speed baud rate
	SYNC = 0;					// Enable the asynchronous serial port
	SPEN = 1;					// Enables the pins RC7 and RC6 as serial port pins
	CREN = 1;					// Enables continous receive
	TX9 = 0;					// Select 8-bit transmission
	RX9 = 0;					// Select 8-bit reception
	TXEN = 1;					// Enables the Transmission
}

/*-----------------------------------------------*/

void uart_puts(const char *p){
	 while(*p != '\0'){
	    uart_putc(*p);	
    	p++;     
	 }	
}
/*-----------------------------------------------*/

void uart_put_array(char *pt){
	 while(*pt != '\0'){
	    uart_putc(*pt);
    	pt++;     
	 }	
}



void uart_putc(unsigned char data)
{
	while(!TXIF)		// set when register is empty
		continue;

	TXREG = data;
}

/*-----------------------------------------------*/

unsigned char uart_getc(void)
{
	if(OERR)			// Clear overrun error
	{
		CREN = 0;		// Resetting the receive logic
		DelayMs(1);
		CREN = 1;
	}
	
	while(!RCIF)		// Wait...
		continue;

	return RCREG;
}

/*-----------------------------------------------*/
