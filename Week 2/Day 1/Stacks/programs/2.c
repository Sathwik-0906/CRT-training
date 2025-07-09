#include<stdio.h>
#include<stdlib.h>

#define size 100
char stack[size];
int top=-1;
void push(char ch)
{
    if(top==size-1)
    {
        printf("Stack is full");
    }
    else
    {
        top=top+1;
        stack[top]=ch;
    }
}
char pop()
{
    char ch;
    if(top==-1)
    {
        return '0';
    }
    else
    {
        ch=stack[top];
        top=top-1;
    }
    return ch;
}
void main()
{
    char s[size];
    int i;
    printf("Enter sts: ");
    gets(s);
    for(i=0;s[i]!='\0';i++)
    {
        push(s[i]);
    }
    printf("rev of str: ");
    while(top!=-1)
    {
        printf("%c",pop());
    }
}