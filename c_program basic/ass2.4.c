#include<stdio.h>
void main()
{
	int n,sumofeven=0,sumofodd=0,i;
	printf("Enter the length n\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	if(i%2==0)
	sumofeven +=i;
	else
	sumofodd +=i;
	printf("Sum of even is %d",sumofeven);
	printf("Sum of odd is %d",sumofodd);
}
