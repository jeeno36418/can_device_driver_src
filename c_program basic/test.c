#include <stdio.h>
#include <math.h>
int fibonacci(int x,int *previous,int *next);
void main()
{
	int s;
	static int f1=0,f2=1;

	printf("Enter the number for fibonacci series\n");

	scanf("%d",&s);
	printf("The fiboacci series for the sequence %d are\n  ",s);
	fibonacci(s,&f1,&f2);
}

int fibonacci(int x,int *previous, int *next)
{ 
volatile int f;
	
	if(x==1)
	{
		f=*previous+*next;
		printf("%d  ",f);
	}
	else
	{
		f=*previous+*next;
		*next=*previous;
		*previous=f;
		printf("%d  ",f);
		fibonacci((x-1),previous,next);
	}
}

