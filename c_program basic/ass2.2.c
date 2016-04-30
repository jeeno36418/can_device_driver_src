//2.	Write a C program to find the Prime number.
#include<stdio.h>
void main()
{
	int num,div,i,count=0;
	printf("Enter a number\n");
	scanf("%d",&num);
		for(i=2;i<num;i++)
	{	{
		if(num%i==0)
		 {count++;
		 break;
	     }
		}
	}
	if(count>=1)
	printf("%d is not prime number",num);
	else
	printf("%d is a prime number",num);
}
