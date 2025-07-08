
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*nn,*head,*tail,*temp;

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

void main()
{
    insert();
    display();
}