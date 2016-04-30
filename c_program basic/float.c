#include<stdio.h>
#include<math.h>
void main()
{
	float f, i,r,p,n;
	
	printf("enter p");
	scanf("%f",&p);
	printf("enter r");
	scanf("%f",&r);
	printf("enter n");
	scanf("%f",&n);
	i=r/100;
	f=p*pow((1+i),n);
	printf("f=%f i=%.2f \n",f,i);
}
