#include"header.h"
// int a;
 int main()
 {
   int a=555,*ptr=&a,b=*ptr;
   printf("%d %d %d",a,--*&b,*ptr++);
   return(0);
 } 

