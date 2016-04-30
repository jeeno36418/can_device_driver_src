#include "header.h"

void main()
{
	typedef struct
	{
		int password;
		char name[5];
	}pswrd;
	pswrd *str_ptr;
	pswrd pswrd_data={123,"kanna"};
	
	
	int i=10;
	int *ptr;
	str_ptr=&pswrd_data;
	ptr=&i;
	printf("add of i %d address of ptr %d  password %d %s %s",&i,&ptr,pswrd_data.password,pswrd_data.name,str_ptr->name);
}
