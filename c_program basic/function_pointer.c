#include"header.h"
#include"function.c"
typedef struct 
{
	int day;
	int month;
	int year;
}dob_t;
typedef struct 
{
	char name[10];
	int age;
	dob_t dob;
}employee_detail_table;
int i;
void main()
{
	void *(*fnt_ptr )(void *, void *);
	fnt_ptr=add;
	int x=9,y=8;
	int *x1=(int *)fnt_ptr(&x,&y);
	employee_detail_table *ptr;
#if 0	
employee_detail_table employee_details[3]=
{
	"kanna",21,8,9,1988,
	"kumar",20,23,1,1989,
	"mathi",19,16,9,1989
};
ptr=employee_details;
for(i=0;i<3;i++)
	printf("Name:%s\nAge:%d\ndob:%d-%d-%d\n",employee_details[i].name,employee_details[i].age,employee_details[i].dob.day,employee_details[i].dob.month,employee_details[i].dob.year);
printf("%d,%d",ptr[0].dob.day,&ptr);
#endif
employee_detail_table employee_details=
{
	"kanna",21,8,9,1988
	
};
ptr=&employee_details;
printf("%d,%s",ptr->dob.day,*ptr);
}


