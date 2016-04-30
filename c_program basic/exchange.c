#include"header.h"
#ifndef __exchange_c
#define __exchange_c
void str_del(char *);
void str_common(char *,char *);
/*char name[]="accelerationn";
str_del(name);
printf("%s",name);
}*/
 void str_del(char *e)
 {
 	int i=0,j=0,temp;
 	for(i=0;*(e+i)!='\0';i++)
 	{ 
 	  for(j=0;*(e+j)!='\0';j++)
 	  {
 	  	if(j==i)
 	  	{
		   continue;}
 	  	if(*(e+i)==*(e+j))
		 {temp=j;
		 while(*(e+temp)!='\0')
		   {
		   *(e+temp)=*(e+temp+1);
		   temp++;
	       }
		   
 	      }
 	     
	   }
	 }
 }
 void str_common(char *str1,char *str2)
{
	int i,j,temp=0;
	for(i=0;*(str1+i)!='\0';i++)
	{
		for(j=0;*(str2+j)!='\0';j++)
		{
			if(*(str1+i)==*(str2+j))
			{
				*(str1+temp)=*(str1+i);
				temp++;
			}
		}
	}
	for(i=temp;temp<sizeof(str1);temp++)
	*(str1+temp)='\0';
}

 #endif
