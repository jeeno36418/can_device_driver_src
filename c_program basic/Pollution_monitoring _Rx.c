#include<pic.h>
#include"delay.c"
#include"lcd_driver.c"


__CONFIG(0x1932);

void main()
{
	
	TRISB = 0xFF;
	TRISA = 0x00;
	ADCON1 = 0x06;
	PORTA = 0x00;
	PORTB = 0x00;

	
	setup_lcd_port();
	lcd_init();
	lcd_goto_pos(1);
	lcd_puts("Pollution Moniter");

	
	while(1)
	{		
		
			
					if(RB0 == 1)
					{
					RA0 = 1;
					lcd_goto_pos(17);
					lcd_puts("Alert");
					}
					else
					{
					RA0 = 0;
					lcd_goto_pos(17);
					lcd_puts("     ");
					}
	}
}

