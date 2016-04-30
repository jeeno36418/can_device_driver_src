#include<pic.h>
#include"delay.c"
#include"lcd_driver.c"
#include"adc_driver.c"


__CONFIG(0x1932);

void main()
{
	
	TRISB = 0x00;
	PORTB = 0x00;
	TRISC = 0x00;
	PORTC = 0x00;

	unsigned char adc1,adc2;
	setup_lcd_port();
	lcd_init();
	adc_init();
	lcd_goto_pos(1);
	lcd_puts("Temp1:");
	
	while(1)
	{		
			adc_channel(0);
			adc1 = adc_res();
			lcd_goto_pos(7);
			lcd_putn(adc1);
			
					if(adc1 > 150)
					{
					RB0 = 1;
					RC0 = 1;
					RC1 = 0;
					}
					else
					{
					RC0 = 0;
					RC1 = 0;
					RB0 = 0;
					}
		}
}
