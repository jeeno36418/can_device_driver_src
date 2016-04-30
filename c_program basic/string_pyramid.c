#include<stdio.h>
void main()
{
 char str[50];
 int middle,len,i,j,k;
 printf("enter a string\n");
 scanf("%s",str);
 for(len=1;*(str+len)!='\0';len++);
 if(len%2==0)
 {middle=len/2-1;
 j=middle;
 k=middle+1;
 }
 else
 {
 	middle=len/2;
 	k=j=middle;
 }
 for(i=0;i<middle;i++)
 {
 
 *(str+j)=32;
 *(str+k)=32;
 
 printf("%s\n",str);
 j--;
 k++;

 } 
}
