#include"function.h"
extern void* add(void* x, void* y )
{
int *x1=(int *)x;
int *y1=(int *)y;
n= *x1+*y1;
return &n;
}

