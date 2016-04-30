//1.	Write a program to find the biggest of 3 numbers. (Decision-making, Bit-wise operations, Branching and Looping)

#include<stdio.h>
#include<conio.h>
void main (void)
{
	int i,j,k;
	printf("Enter a three number\n");
	scanf("%d %d %d",&i,&j,&k);
	if(i>j&&i>k)
	{
		printf("i=%d is greater than j=%d and k=%d",i,j,k);
		
	}
	else
	{
		if(j>k)
		printf("j=%d is greater than i=%d and k=%d",j,i,k);
		else
		printf("k=%d is greater than i=%d and j=%d",k,i,j);		
	}
	
}
