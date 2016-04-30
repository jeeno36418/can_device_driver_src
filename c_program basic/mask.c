 #include"header.h"
 #ifndef _mask_c
 #define _mask_C


    int mask(int j)
       { 
	   int i, a[9];
       
       printf("\n binary value of %d is ",j);
	   for(i=8;i>=0;i--)
	   {
	   	a[i]=j%2;
	   	
	   	j/=2;
	   }
	   for(i=0;i<=8;i++)
	   {
	      printf("%d",a[i]);
	   }
	   
	   return 0;
	   }     
#endif
