#include"header.h"
void main()
{
	unsigned int a=0xff;
unsigned	int i=2;
	i<<=1;
	i=~i;
	a&=i;
	printf("%d",a);
}
