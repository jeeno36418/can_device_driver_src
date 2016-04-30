/*---------------------------------------------------------------------------------
*
*							 UART DRIVER (PIC micro - PC) 
*
*	File name: uart_driver.c
*
*	Description: 	PIC16F87x - micro
*					PORTC - Tx and Rx 
*
*	Function -  uart_init(BAUD_RATE,FOSC)
*				BAUD_RATE in Bits Per Second - Ex: 1200 or 9600
*				FOSC in MHz - Ex: 16 or 4
*---------------------------------------------------------------------------------*/

#include <pic.h>
#include "delay.c"



void uart_puts(const char *);
void uart_put_array(char *);
void uart_putn(unsigned int);
void uart_putnd(unsigned int,char);
void uart_putc(unsigned char);
void uart_init(unsigned int baud, unsigned char fosc);
unsigned char uart_getc(void);

/*-----------------------------------------------*/

#ifndef NUM
#define NUM
const char num[10]={'0','1','2','3','4','5','6','7','8','9'};
#endif

#ifndef DIG_MAX
#define DIG_MAX 6
#endif


/*-----------------------------------------------*/

//void main(){}

/*-----------------------------------------------*/

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

void uart_puts(const char *p)
{
	 while(*p != '\0'){
	    uart_putc(*p);	
    	p++;     
	 }	
}
/*-----------------------------------------------*/

void uart_put_array(char *pt)
{
	 while(*pt != '\0'){
	    uart_putc(*pt);
    	pt++;     
	 }	
}
/*-----------------------------------------------*/

void uart_putn(unsigned int n)
{
     unsigned int no = n;
	 char dig=0;
     while(no)
     {
      no = no/10;
      dig++;
     }
	 if(n == 0)
		dig = 1;
     uart_putnd(n,dig);
}

/*-----------------------------------------------*/

void uart_putnd(unsigned int n,char d)
{
	char array[DIG_MAX];
	array[d] = '\0';
	do
	{
		d--;
		array[d] = (n%10) + 48;
		n = n/10;	
	}while(n);

	uart_puts(array);    
}

/*-----------------------------------------------*/


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
