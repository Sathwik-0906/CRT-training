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

void delatbeg()
{
    head=head->next;
}

void display()
{
    temp=head;
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}


void main()
{
    insert();
    display();
    // addbig();
    // addend();
    // addpos();
    delatbeg();
    display();
}