#include"header.h"
struct node
{
	int data;
	struct node *link;
};
typedef struct node NODE;
NODE *newn, *first;

void main()
{
void creation();
creation();
newn->data=50;
}
void creation()
{
	printf("Enter item for list");
	scanf("%d",newn->data);
	printf("%d",newn->data);
}

