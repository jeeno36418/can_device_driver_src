/*---------------------------------------------------------------------------------
*
*									 LCD DRIVER
*
*	File name: lcd_driver.c
*
*	Description: 	PIC16F87x - micro
*					PORTD - data (8 pins)
*				 	PORTE - control (3 pins)	
*---------------------------------------------------------------------------------*/

#include <pic.h>
#include "delay.c"

/*-----------------------------------------------*/

void setup_lcd_port(void);
void lcd_puts(const char *);
void lcd_put_array(char *);
void lcd_putn(unsigned int);
void lcd_putc(unsigned char);
void lcd_puta(unsigned char);
void lcd_goto(unsigned char);
void lcd_goto_pos(unsigned char);
void lcd_clrscr(void);
void lcd_init(void);
void lcd_write(unsigned char,unsigned char);

/*-----------------------------------------------*/


#define BACK_LIGHT RE0
#define ENABLE RE1
#define REG_SELECT RE2

/************************************/

#define COMMAND_REG	0
#define DATA_REG	1

#ifndef DIG_MAX
#define DIG_MAX 6
#endif

#define LATCH_ENABLE DelayUs(1);ENABLE=1;DelayUs(10);ENABLE=0;DelayMs(2)

/*-----------------------------------------------*/

//void main()
//{
//}

/*-----------------------------------------------*/

void lcd_puts(const char *p){
	 while(*p != '\0'){
	    lcd_write(*p,DATA_REG);
    	p++;     
	 }	
}
/*-----------------------------------------------*/

void lcd_put_array(char *pt){
	 while(*pt != '\0'){
	    lcd_write(*pt,DATA_REG);
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

void lcd_goto(unsigned char cnt){		//cnt = ( 1 ... 80) for 20*4 LCD								
	if(cnt>60)
		lcd_write((0xD4+(cnt-61)),COMMAND_REG);
	else if(cnt>40)
		lcd_write((0x94+(cnt-41)),COMMAND_REG);
	else if(cnt>20)
		lcd_write((0xC0+(cnt-21)),COMMAND_REG);
	else
		lcd_write((0x80+(cnt-1)),COMMAND_REG);
}	
/*-----------------------------------------------*/

void lcd_goto_pos(unsigned char cnt){		//cnt = (1 ... 32) for 16*2 LCD
	if(cnt>16)
		lcd_write((0xC0+(cnt-17)),COMMAND_REG);
	else
		lcd_write((0x80+(cnt-1)),COMMAND_REG);
}	
/*-----------------------------------------------*/

void lcd_putc(unsigned char c){
   lcd_write(c,DATA_REG);	
}
/*-----------------------------------------------*/

void lcd_init(void){               // Initializing LCD 
   lcd_write(0x38,COMMAND_REG);    // Set lcd to 2 display lines and 5*7 font size
   lcd_write(0x0C,COMMAND_REG);    // Display ON & Cursor OFF & Blinking OFF 
   lcd_write(0x01,COMMAND_REG);    // Clear Display 
   lcd_write(0x80,COMMAND_REG);    // Set DDRAM address 
}
/*-----------------------------------------------*/

void lcd_write(unsigned char c,unsigned char reg){
    PORTD = c;
    reg ? REG_SELECT=1 : REG_SELECT=0;
    LATCH_ENABLE;
}
/*-----------------------------------------------*/

void lcd_clrscr()
{
	lcd_write(0x01,COMMAND_REG);
	lcd_write(0x80,COMMAND_REG);
}
/*-----------------------------------------------*/

void lcd_puta(unsigned char data)
{
	lcd_write(data,COMMAND_REG);
}
/*-----------------------------------------------*/

void setup_lcd_port(){
	TRISD = 0x00;
	TRISE = 0x00;
	ADCON1 = 0x06;
}
/*------------------------------------------------*/
