#include<pic.h>
#include"delay.c"

__CONFIG(0x1932);



void main()
{
	unsigned int key_1=0,key_2=0,key_3=0;

	ADCON1 = 0x06;		// POARTS As Digital
	TRISA = 0x1f;		// POART State 
	PORTA = 0x00;		// Clear PORTS
	TRISD = 0x00;
	PORTD = 0x00;
	
	while(1)
	{
		if(RA1 ==1)
		{
		key_1 = 1;
		}
		
		if(RA1 == 0 && key_1 == 1)				// Forword
		{
		PORTD = 0x02;
		DelayMs(200);
		key_1 = 0;
		}

			if(RA2 ==1)
			{
			key_2 = 1;
			}
			
			if(RA2 == 0 && key_2 == 1)			// Reverse		
			{
			PORTD = 0x01;
			DelayMs(100);
			key_2 = 0;
			}
				
			if(RA4 ==1)
			{
			key_3 = 1;
			}
				
			if(RA4 == 0 && key_3 == 1)			// Stop
			{
			PORTD = 0x00;
			DelayMs(100);
			key_3 = 0;
			}
		
	
	}
}