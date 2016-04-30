
#include <pic.h>
#include "p_lcdn.c"
#include "p_driver_crdt_card.c"

#define col4 RB4
#define col3 RB5
#define col2 RB6
#define col1 RB7

__CONFIG(HS & WRTEN & WP3 & WDTDIS & PWRTEN & BORDIS & LVPDIS & DEBUGDIS & UNPROTECT & DUNPROT);

void disp_etr_pw(void);
void disp_correct(void);
void disp_not_correct(void);

unsigned char scan(unsigned char a);
unsigned char key_scan(void);

void delay(unsigned char);

void main()
{
 static unsigned char card_value,pre_key,temp;
 static unsigned char msgno,p,i,j,k,f=0;
 TRISC=0X80;  // Configure PORTC as O/P -RF Transmitter
 TRISA=0x0F;    // Configure PORTA0 as O/P
 ADCON1=0x06; // Make RA) as digital O/P pin
 TRISD=0x00;  // for LCD data pins
 TRISE=0x00;  // for LCD control pins
 TRISB=0XF0;	// 4 msb(column) - i/p ; 4 lsb(row) - o/p
 RBPU=0;		//enables internal pull up

 PORTA=0x00;  // clear PORTA
 PORTC=0x00;  // clear PORTC
 PORTD=0x00;  // Clear PORTD
 PORTB=0x00;  // Clear PORTB
 RA0=0;       // Clear RA0
 
 RC2=1; // Red LED ON
 init_sci();
 lcd_init();
 DelayMs(250);
 
 while(1)
 {
  CREN = 1;   //enable continuous receive
  k=0;i=0;p=0;
  PORTB=0x00;
  DelayMs(250);
  //temp=PORTA;
  PORTC=0x00;
  RC2=0; // Red LED OFF
//---------wait state----------//
   while(PORTA==15);
    temp=PORTA;
//-------card scaning---------//

  if(temp!=15) 
  {  
   card_value = scan(temp);

   lcd_cmd_write(0xC8);
   DelayMs(5);
   lcd_data_write(card_value);
   DelayMs(5);
  

//------asking for Password------//
   disp_etr_pw();
   DelayMs(100);

//-----Key Scanning --------//
   while(PORTB==0xF0);
   if(PORTB!=0xF0)
   {
    DelayMs(50);
    if(PORTB!=0xF0)
     pre_key = key_scan();

   lcd_cmd_write(0xD3);
   DelayMs(5);
   lcd_data_write(pre_key);
   DelayMs(5);

//------Card Checking-------//
    if(pre_key == card_value)
    { 
     f=1;
     disp_correct();
     DelayMs(100);
    }
 }
}
}
}
     unsigned char scan(unsigned char a)
{
 unsigned char temp;
 switch (a)
 {
  case 0:
   temp='0';break;
  case 1:
   temp='1';break;
  case 2:
   temp='2';break;
  case 3:
   temp='3';break;
  case 4:
   temp='4';break;
  case 5:
   temp='5';break;
  case 6:
   temp='6';break;
  case 7:
   temp='7';break;
  case 8:
   temp='8';break;
  case 9:
   temp='9';break;
  case 10:
   temp='A';break;
  case 11:
   temp='B';break;
  case 12:
   temp='C';break;
  case 13:
   temp='D';break;
  case 14:
   temp='E';break;
 }
 return temp;
}

unsigned char key_scan()
{
 static unsigned char row[]={0x7,0xB,0xD,0xE};
 static unsigned char key[4][4] = {'4', '8', 'C', '0',		// keypad matrix values are provided here
   			    	               '3', '7', 'B', 'F',
				         		   '2', '6', 'A', 'E',
							       '1', '5', '9', 'D'};
 unsigned char i,temp;

 for(i=0;i<4;i++)
 {
  PORTB=row[i];  //making row as 0 one by one
  if(!col1)
  {
   temp=key[i][0];
   while(!col1)
    continue;
  }

  if(!col2)
  {
   temp=key[i][1];
   while(!col2)
    continue;
  }

  if(!col3)
  {
   temp=key[i][2];
   while(!col3)
    continue;
  }

  if(!col4)
  {
   temp=key[i][3];
   while(!col4)
    continue;
  }
 } 
 return temp;
}

void disp_etr_pw()
{
 unsigned char i,a[]="Enter Password";
 lcd_cmd_write(0x96);
 DelayMs(5);
 for(i=0;i<14;i++)
 {
  lcd_data_write(a[i]);
  DelayMs(5);
 }
}

void disp_correct()
{
 unsigned char i,a[]="Correct.......";
 lcd_cmd_write(0x96);
 DelayMs(5);
 for(i=0;i<14;i++)
 {
  lcd_data_write(a[i]);
  DelayMs(5);
 }
}

void disp_not_correct()
{
 unsigned char i,a[]="Not Correct....";
 lcd_cmd_write(0x96);
 DelayMs(5);
 for(i=0;i<15;i++)
 {
  lcd_data_write(a[i]);
  DelayMs(5);
 }
}