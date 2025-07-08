
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*nn,*head,*tail,*temp,*prev;

void insert()
{
    int d,val;
    for(int i=1;i<=4;i++)
    {
        
        printf("Enter %d node: ",i);
        scanf("%d",&val);
        nn=(struct node*)malloc(sizeof(struct node));
        nn->data=val;
        nn->next=NULL;
        if(head==NULL)
        {
            head=nn;
            tail=nn;
            tail->next=head;
        }
        else
        {
            tail->next=nn;
            tail=nn;
            tail->next=head;
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
        if(temp==head)
        {
            break;
        }
    }
    printf("%d ",temp->data);
}

void rev()
{
    struct node *cur,*next;
    prev=tail;
    cur=head;
    
    while(cur)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
        if(cur==head)
        {
            break;
        }
    }
    head=prev;
    tail=cur;
}
void main()
{
    insert();
    display();
    rev();
    printf("\n");
    display();
}