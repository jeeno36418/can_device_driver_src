#include"header.h"
#include"exchange.c"
void str_common(char *,char *);
void main()
{
	char no[32]="no match found";
	char str1[32]="\0";
	char str2[32]="\0";
	char str3[32]="\0";
	printf("enter three string\n");
	scanf("%s %s %s",str1,str2,str3);
//printf("%s\n\n%s\n\n%s\n\n",str1,str2,str3);
	str_del(str1);
	str_del(str2);
	str_del(str3);
	printf("\nafter eliminating same character\n\n%s\n\n%s\n\n%s\n\n \n",str1,str2,str3);
	str_common(str1,str2);
	str_common(str1,str3);
	if(*(str1+0)=='\0')
	strcpy(str1,no);
	printf("common character are= %s",str1);
	
}

