#include"header.h"
void string_print_aftermatch(char *,char *);
void string_print_beforematch(char *,char *);
void main()
{
char str1[50];
char str2[32];
printf("enter two string\n");
gets(str1);
gets(str2);

string_print_aftermatch(str1,str2);
//string_print_beforematch(str1,str2);
}
void string_print_aftermatch(char *s1,char *s2)
{int i,j,temp,check;
	for(i=0;*(s1+1)!='\0';i++)
	 {
	   if(*(s1+i)==*(s2))//if first letter is matched.compare with rest of the letter in that word
	   {temp=i+1;
	    for(j=1;*(s2+j)!='\0';j++)
	      {
	      	check=(*(s1+temp)-*(s2+j));
	      	temp++;
	      	
			
		  }
       }
       if(check==0)
       {printf("%s\n",(s1+temp));
       *(s1+i)='\0';
       printf("%s\n",s1);
       break;
	   }
     }
}
void string_print_beforematch(char *s1,char *s2)
{  
int i,j,temp,check=!0;
	for(i=0;*(s1+1)!='\0';i++)
	 {
	   if(*(s1+i)==*(s2))//if first letter is matched.compare with rest of the letter in that word
	   {temp=i+1;
	    for(j=1;*(s2+j)!='\0';j++)
	      {
	      	check=(*(s1+temp)-*(s2+j));
	      	temp++;
	      	
			
		  }
       }
       if(check==0)
       {*(s1+i)='\0';
	   printf("%s\n",s1);
       break;
	   }
     }
	
}
