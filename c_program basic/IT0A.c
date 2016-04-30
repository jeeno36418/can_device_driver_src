#include<stdio.h>
#include<string.h>
 int itoa(int ,char *);
 int size,integer;
 char name[10]={0};
 void main()
 {
	 
	 
	 printf("enter a number");
	 scanf("%d",&integer);
	 size=itoa(integer,name);
	 printf("\n size=%d name=%s",size,name);
 }
 /*Function return size of string and convert signed  *
  *integer to ascii value and store them in array of  *
  *character with NULL at the end of the array        */
 int itoa(int value,char *ptr)
 {
 	int count=0,temp;
 	if(ptr==NULL)
	return 0;	
	if(value==0)
	{   
	 	*ptr='0';
		return 1;
	}
	 	
	 if(value<0)
	 {
	    value*=(-1);	
	    *ptr++='-';
        count++;
     }
     for(temp=value;temp>0;temp/=10,ptr++);
     *ptr='\0';
     for(temp=value;temp>0;temp/=10)
	 {
	 	*--ptr=temp%10+'0';
	 	count++;
	 }
	  return count;
     
 }
