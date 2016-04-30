#include"header.h"
int sum(int x);
int main(void)
{
int num; 
printf("Enter a 5 digit number\n");
scanf("%d",&num);

printf("The sum of 5digit number=%d is %d",num,sum(num));

//return 0;

}
int sum(int x)
{

	if(x==0)
	return x;
	else
 	{
	x=x%10+sum(x/10);
//	return 65;	
	}
	
}
