#include <stdio.h>

int main()
{
    int a[]={8,18,28,38,48};
    int *ptr = NULL;
    ptr=&a[2];
    --ptr;
    //now points to a[0]
    --*ptr;
    //value at which pointer is pointing is incremented i.e a[0] = 1+1=2
    ++ptr;
    //now points to a[1]āā
    ++*ptr;
    //value at which pointer is pointing is decremented i.e a[1] = 11-1=10
    printf("%d,%d,%d",ptr[0],ptr[1],ptr[-1]);
}