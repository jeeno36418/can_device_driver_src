#ifndef _DAYFINDER_H
#define _DAYFINDER_H
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int x=10;
typedef struct
{
	int day;
	int month;
	int year;
}dob;
typedef struct
{
	const char name_of_day[15];
}days;

days weeks[]=
{"SUNDAY",
"MONDAY",
"TUESDAY",
"WEDNESDAY",
"THURSDAY",
"FRIDAY",
"SATURDAY",
"INVALID DATE" , //jaya_SID
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

int months[11]=
{
	31,28,31,30,31