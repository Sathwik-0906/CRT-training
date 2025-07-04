#include <stdio.h>

int main()
{
    int a[]={1,11,21,31,41,51};
    int *ptr = NULL;
    ptr=&a[1];
    --ptr;
    //now points to a[0]
    ++*ptr;
    //value at which pointer is pointing is incremented i.e a[0] = 1+1=2
    ++ptr;
    //now points to a[1]āā
    --*ptr;
    //value at which pointer is pointing is decremented i.e a[1] = 11-1=10
    printf("%d,%d,%d,%d,%d",a[0],a[1],a[2],a[3],a[4]);
    return 0;

}