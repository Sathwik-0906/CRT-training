#include<stdio.h>
#include<stdlib.h>
#define size 4
int stack[size];
int top=-1;
void push()
{ 
    int ele;
    if
    (top==size-1)
    {
        printf("stack is overflow or full");
    }
    else
    {
        printf("Enter the element: ");
        scanf("%d",&ele);
        top=top+1;
        stack[top]=ele;
    }
    printf("\n");
}
void display()
{
    if(top==-1)
    {
        printf("stack is empty");
    }
    else
    {
    for(int i=top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }
    }
    printf("\n");
    
}
void pop()
{
    if(top==-1)
    {
        printf("stack is empty");
    }
    else
    {
        printf(" poped %d",stack[top]);
        top=top-1;
    }
    printf("\n");
    
}

void peek()
{
    if(top==-1)
    printf("Stack is empty");
    printf("peek ele is %d",stack[top]);
    printf("\n");
    
}
int main()
{
    int s;
    while(1)
    {
        printf("1:push\n2:pop\n3:display\n4:peek\n5:exit\n");
        printf("\n");
        printf("choose option: ");
        scanf("%d",&s);
        switch(s)
    {
        case 1:push();
        break;
        case 2:pop();
        break;
        case 3:display();
        break;
        case 4:peek();
        break;
        case 5:exit(0);
        break;
        default:printf("Enter valid number.");
    }
    }
    
}