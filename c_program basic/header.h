#ifndef _header_h
#define _header_h
#include<stdio.h>
#include<conio.h>
#include<string.h>
int x=10;
typedef struct
{
	char name[15];
}days;

days weeks[]=
{"SUNDAY",
"MONDAY",
"TUESDAY",
"WEDNESDAY",
"THURSDAY",
"FRIDAY",
"SATURDAY",
"jayaprakash" , //jaya_SID
};

days *ptr;

/*following table is used for storing sid */
typedef enum 
{
	sunday=0,// stiring identifier
	
	monday,
	tuesday,
	wednesday,
	thursday,
	friday,
	saturday,
	jaya_SID
	}day;

#endif

