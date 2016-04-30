#include<pic.h>
#include "delay.c" 
#include "i2c_lcd_driver_new.c"
#include "uart_driver.c"

/*--------------------------------------------*/

__CONFIG(0x1932);

/*--------------------------------------------*/

void main(){
	
	unsigned char c;
	setup_i2c_port();
	setup_i2c_master();
	uart_init(9600,16);				// Initialize UART to 9600 baud-rate
	DelayMs(100);
	lcd_init();
	lcd_goto(1);
	lcd_puts("FV I2C LCD Check");

	

	while(1)
	{
	c = uart_getc();
	uart_putc(c+1);
	lcd_goto_pos(17);
	lcd_putc(c);
	}
}
/*--------------------------------------------*/



