#include<pic.h>
#include "delay.c" 
#include "uart_driver.c"
#include "lcd_driver.c"

__CONFIG(HS & WRTEN & WP3 & WDTDIS & PWRTEN & BORDIS & LVPDIS & DEBUGDIS & UNPROTECT & DUNPROT);

void uart_int_config();

static unsigned char key,pos;

void main()
{
       setup_lcd_port();

		DelayMs(100);
		lcd_init();
		lcd_puts("rcv_data");
		
		uart_init(9600,16);
		uart_int_config();
		uart_puts("Sarathi UART Check");
		while(1)
		{
		//	lcd_clrscr();
			if(key){
				key = key-48;
				lcd_puta(pos);
				lcd_putn(key);
				DelayMs(5);
				uart_putn(key+1);	
				key = 0;
			}
		}
}
//#pragma interrupt_level 0
static void interrupt
isr(void)		
{
	if(RCIF)
	{
		if(OERR)			// Clear overrun error
		{
			CREN = 0;		// Resetting the receive logic
			DelayUs(100);
			CREN = 1;
		}
		key = RCREG;		// Read the RCREG of UART receiver		
		pos = 0xC5;
		RCIF = 0;		
	}
}
	

void uart_int_config()
{
	// UART receiver interrupt configuration
	RCIF = 0;			// Clear uart receiver flag bit
	RCIE = 1;			// Receiver interrupt bit enable
	PEIE = 1;			// Enables all peripheral interrupts
	GIE = 1;			// Enable the global interrupt 
}

