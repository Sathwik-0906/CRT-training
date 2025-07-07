#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
}*nn,*head,*temp,*tail;
void insert()
{
    int val,i;
    
    for(i=1;i<=4;i++)
    {
        nn=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&val);
        
        nn->data=val;
        nn->next=NULL;

        if(head==NULL)
     {
        head=nn;
        tail=nn;
     }
        else
     {
        tail->next=nn;
        tail=nn;
     }
    
    }
    
}

void display()
{
    temp=head;
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}


void main()
{
    insert();
    display();
}