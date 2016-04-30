
#include<pic.h>
#include "delay.c"
#include "uart_driver.c"
#include "lcd_driver.c"

__CONFIG(0x1932);

void main()
{
	unsigned char c;
	setup_lcd_port();				// Port initialization for LCD
	uart_init(9600,16);				// Initialize UART to 9600 baud-rate 

	DelayMs(100);
	lcd_init();
	lcd_puts("uart_check");
        uart_puts("kanna");

	while(1)
	{
		c = uart_getc();
		uart_putc(c+1);
		lcd_goto_pos(17);
		lcd_putc(c);
	}
}
