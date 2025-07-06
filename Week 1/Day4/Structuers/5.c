#include<stdio.h>
void swap(int *p1, int *p2)
{
int t;
t=*p1;
*p1=*p2;
*p2=t;
}
void main()

{
int a,b;
a = 10
b = 20
printf("Values before swap a=%d, b=%d",a,b);
swap(&a,&b);
printf("Values after swap a=%d, b=%d",a,b);
}