#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
}*nn,*head,*temp,*tail;
void insert()
{
    int val,i,n;
    printf("Enter size: ");
    scanf("%d",&n);
    printf("Enter Node data: ");
    for(i=1;i<=n;i++)
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
void addbig()
{
    int val;
    nn=(struct node*)malloc(sizeof(struct node));
    printf("Add node at beig: ");
    scanf("%d",&val);
    nn->data=val;
    nn->next=NULL;
    while(head==NULL)
    {
        head=nn;
    }
    nn->next=head;
    head=nn;
}
void addend()
{
    int val;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    nn=(struct node*)malloc(sizeof(struct node));
    printf("Add node at end: ");
    scanf("%d",&val);
    nn->data=val;
    nn->next=NULL;
    temp->next=nn;
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
    // addbig();
    addend();
    display();
}