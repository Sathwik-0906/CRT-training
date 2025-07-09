#include<stdio.h>
#define size 10
int stack[size];
void main()
{
    int a[]={10,20,30,40,50};
    int p1,p2,s,i;
    s=sizeof(a)/sizeof(arr[0]);
    p1=s-1;
    p2=0;
    for(i=0;i<s/;i++)
    {
        stack[p2]=a[p1];
        p2+=1;
        p1-=1;
    }
    p1=-1;
    while(p2!=0)
    {
        p1=p1+1;
        a[p1]=stack[p2-1];
        p2=p2-1;
    }
    for(i=0;i<=p1;i++)
    printf("%d ",a[i]);

    
}