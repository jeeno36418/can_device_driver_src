#include"header.h"
void main()
{
	int num,num1,rev=0,mul=1,temp;
	printf("enter number ");
	scanf("%d",&num);
	temp=num;
	while(temp/=10)
	{
		mul*=10;
	}
	temp=num;
	while(temp)
	{
		num1=temp%10;
		rev+=num1*mul;
		mul/=10;
		temp/=10;
	}
	printf("\nreversed number is %d \n",rev);
	if(rev==num)
	printf("palindrome");
	else
	printf("not a palindrome");
}

