/*--------------------------------------------------------------*/
/*			  Selects Analog channels AN0 to AN4				*/
/*--------------------------------------------------------------*/
/*  	 ADC acq. freq (app)  -  10000 samples/sec (9900 typ)	*/
/*--------------------------------------------------------------*/

//#include <pic.h>
//#include "delay.c"

/*--------------------------------------------------------------*/

void adc_init(void);
void adc_channel(unsigned char);
unsigned char adc_res(void);
unsigned int adc_res_10_bit(void);

/*--------------------------------------------------------------*/

//void main(){}

/*--------------------------------------------------------------*/

void adc_init()
{
	DelayMs(100);
	ADCON1 = 0x82;			// Configures the functions of the port pins (only PORTA pins are used)
}

/*--------------------------------------------------------------*/

void adc_channel(unsigned char ch)
{
	DelayUs(100);
	ADCON0 = 193 | (ch << 3); 		// Turns ON the A/D module (selects channels AN0 to AN4 )	
}

/*--------------------------------------------------------------*/

unsigned char adc_res()
{
	ADRESL = 0;				// Clears the contents of the AD result register 
	DelayUs(20);			// Acquisition delay for charging the sampling capacitor 
	ADGO = 1;				// Starts the A/D Conversion 
	
	while(ADGO)				// Waits until the ADGO bit becomes 0 (conversion to complete)
		continue;

	return ADRESL;	 
}

/*--------------------------------------------------------------*/
unsigned int adc_res_10_bit()
{
//	unsigned int left_res, right_res, result;
		

	ADRESL = 0;				// Clears the contents of the AD result register 
	ADRESH = 0;
	DelayUs(20);			// Acquisition delay for charging the sampling capacitor 
	ADGO = 1;				// Starts the A/D Conversion 
	
	while(ADGO)				// Waits until the ADGO bit becomes 0 (conversion to complete)
		continue;
	
	return (((unsigned int)ADRESH)<<8)|(ADRESL);

}
/*-------------------------------------*/





