//3.	Write a C program to generate the fibanocci series.
#include<stdio.h>
void main()
{
	int i,f3,len;
	printf("Enter the number ");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		static int f1=0,f2=1;
		f3=f1+f2;
		printf("%d ",f3);
		f2=f1;
		f1=f3;
		
		
	}
	
}
