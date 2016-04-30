#include"header.h"
void main()
{
	
	typedef struct
			{
		int day;
		int month;
		int year;
	}birth;
	
	
	typedef struct
    {
    	char name[30];
		birth dob ;
		int std;
		char sec;
		
    }student;
	
	birth *ptr;    
	student stud;
	printf("enter the student details:");
	scanf(" %d %d %d ",&stud.dob.day,&stud.dob.month,&stud.dob.year);
	//printf("\nname:%s \ndob:%d %d %d\nstd:%d\nsec:%c ",stud.name,stud.dob.day,stud.dob.month,stud.dob.year,stud.std,stud.sec);
	printf("\ndob:%d %d %d\n ",stud.dob.day,stud.dob.month,stud.dob.year);
	
	if(!((stud.dob.year)%4))
	printf("\nborn in leap year");
	else
		printf("\n not a leap year");
		
	
}
