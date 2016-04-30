#include"header.h"
 main( )
{
long int year, leap, first=1900,nleap,nyear,n;
char day[10]="sunday";
printf("enter the year\n");
scanf("%d",&year);
nyear=(year-first);
year%4==0?(leap=nyear/4-1):(leap=nyear/4);

nleap=nyear-leap;
n=((leap*366)+(nleap*365)+1)%7;
printf("nyear=%d\n leap=%d\n nleap=%d\n n=%d\n" ,nyear,leap,nleap,n);
switch (n)
{
case 0:
	printf("first day of %d is %s",year,day);
	break;
case 1:
	printf("first day of %d is monday",year);
	break;
case 2:
	printf("first day of %d is tuesday",year);
	break;
case 3:
	printf("first day of %d is wednesday",year);
	break;
case 4:
	printf("first day of %d is thursday",year);
	break;
case 5:
	printf("first day of %d is friday",year);
	break;

case 6:
	printf("first day of %d is saturday",year);
	//break;
}
}

