/*--------------------------------------------------------------------------------------
*
*									i2c_lcd_driver.c			
*
*	MicroController	: PIC16F877A
*	Serial Clock	: 100 Khz
*--------------------------------------------------------------------------------------*/

//#include<pic.h>

#ifndef _I2C
#define _I2C
#include "i2c.c"
#endif

//#include "delay.c" 
/*--------------------------------------------*/

void i2c_lcd_data_write(unsigned char data_byte);
void i2c_lcd_ctrl_write(unsigned char ctrl_byte);
void lcd_puts(const char *);
void lcd_put_array(char *);
void lcd_putn(unsigned int);
void lcd_putnd(unsigned int,char);
void lcd_putc(unsigned char);
void lcd_puta(unsigned char);
void lcd_goto(unsigned char);
void lcd_goto_pos(unsigned char);
void lcd_clrscr(void);
void lcd_init(void);
void lcd_cmd_write(unsigned char);
void lcd_data_write(unsigned char);

/*-----------------------------------------------*/

#define RESET (0x00)
#define CMD_REG (0x00)
#define DATA_REG (0x02)
#define ENABLE (0x01)

#ifndef DIG_MAX
#define DIG_MAX 6
#endif

#ifndef NUM
#define NUM
const char num[10]={'0','1','2','3','4','5','6','7','8','9'};
#endif

#define BACK_LIGHT RE0
#define ON	0
#define OFF	1
/*--------------------------------------------*/

//void main(){}

/*--------------------------------------------*/

void i2c_lcd_data_write(unsigned char data_byte){
	i2c_start();									// Send start command
	i2c_byte_write(SLAVE_WR(IOEXP_LCD_DATA));		// Send control byte
	i2c_byte_write(data_byte);						// Send data byte to be stored
	i2c_stop();										// Send stop command
}
/*--------------------------------------------*/

void i2c_lcd_ctrl_write(unsigned char ctrl_byte){
	i2c_start();									// Send start command
	i2c_byte_write(SLAVE_WR(IOEXP_LCD_CTRL));		// Send control byte
	i2c_byte_write(ctrl_byte);						// Send data byte to be stored
	i2c_stop();										// Send stop command
}
/*--------------------------------------------*/

void lcd_puts(const char *p){
	 while(*p != '\0'){
	    lcd_data_write(*p);	
    	p++;     
	 }	
}
/*-----------------------------------------------*/

void lcd_put_array(char *pt){
	 while(*pt != '\0'){
	    lcd_data_write(*pt);	
    	pt++;     
	 }	
}
/*-----------------------------------------------*/

void lcd_putn(unsigned int n){
    unsigned int no;
	unsigned char dig=1;
	char array[DIG_MAX];	
	if(n)
		for(no=n; no/=10; dig++);		
	array[dig] = '\0';			
	do{		
		array[--dig] = (n%10) + 48;			
	}while(n/=10);	

	lcd_puts(array);    
}

/*-----------------------------------------------*/

void lcd_putc(unsigned char c){
   lcd_data_write(c);	
}

/*-----------------------------------------------*/

void lcd_init(void){                 /* Initializing LCD */  
	TRISE0 = 0;
	i2c_lcd_data_write(RESET);	
	i2c_lcd_ctrl_write(RESET);	
    lcd_cmd_write(0x38);             /* Set lcd to 2 display lines and 5*7 font size */
    lcd_cmd_write(0x0C);             /* Display ON & Cursor OFF & Blinking OFF */
    lcd_cmd_write(0x01);             /* Clear Display */
    lcd_cmd_write(0x80);             /* Set DDRAM address */
}
/*-----------------------------------------------*/

void lcd_cmd_write(unsigned char cmd){
   	i2c_lcd_data_write(cmd);
	i2c_lcd_ctrl_write(CMD_REG);			// register select - command
	DelayUs(1);
    i2c_lcd_ctrl_write(ENABLE | CMD_REG);	//Enable pin goes high
    DelayUs(10);
    i2c_lcd_ctrl_write(CMD_REG);			//Enable pin goes low
    DelayMs(2);
}
/*-----------------------------------------------*/

void lcd_data_write(unsigned char data){
   	i2c_lcd_data_write(data);
	i2c_lcd_ctrl_write(DATA_REG);			// register select - data
	DelayUs(1);
    i2c_lcd_ctrl_write(ENABLE | DATA_REG);	//Enable pin goes high
    DelayUs(10);
    i2c_lcd_ctrl_write(DATA_REG);			//Enable pin goes low
    DelayMs(2);
}
/*-----------------------------------------------*/

void lcd_clrscr(){
	lcd_cmd_write(0x01);
	lcd_cmd_write(0x80);
}
/*-----------------------------------------------*/

void lcd_puta(unsigned char data){
	lcd_cmd_write(data);
}
/*-----------------------------------------------*/

void lcd_goto(unsigned char cnt)		//( 1 ... 80)
{
	if(cnt > 60)
		lcd_cmd_write(0xD4+(cnt-61));
	else if(cnt > 40)
		lcd_cmd_write(0x94+(cnt-41));
	else if(cnt >20)
		lcd_cmd_write(0xC0+(cnt-21));
	else
		lcd_cmd_write(0x80+(cnt-1));
}
/*-----------------------------------------------*/	

void lcd_goto_pos(unsigned char cnt){		//cnt = (1 ... 32) for 16*2 LCD
	if(cnt>16)
		lcd_cmd_write(0xC0+(cnt-17));
	else
		lcd_cmd_write(0x80+(cnt-1));
}	
/*-----------------------------------------------*/	
