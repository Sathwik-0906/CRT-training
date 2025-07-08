// del at start and end



//add at start and end

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
}*nn,*head=NULL,*temp=NULL,*tail;
void insert()
{
    int d,val;
    printf("Enter NO of Nodes: ");
    scanf("%d",&d);
    for(int i=1;i<=d;i++)
    {
        printf("Enter %d node: ",i);
        scanf("%d",&val);
        nn=(struct node*)malloc(sizeof(struct node));
        nn->data=val;
        nn->prev=NULL;
        nn->next=NULL;
        if(head==NULL)
        {
            head=nn;
            tail=nn;
        }
        else{
            tail->next=nn;
            tail=tail->next;
        }
    }
}
void add_at_start()
{
    int val;
    printf("\nEnter node at starting: ");
    scanf("%d",&val);
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=val;
    nn->prev=NULL;
    nn->next=NULL;
    head->prev=nn;
    nn->next=head;
    head=nn;
}
void add_at_end()
{
    int val;
    printf("\nEnter node at end: ");
    scanf("%d",&val);
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=val;
    nn->prev=NULL;
    nn->next=NULL;
    tail->next=nn;
    tail=nn;
}

void del_at_start()
{
    printf("\nDel at starting.\n");
    temp=head->next;
    head->next->prev=NULL;
    head=temp;
}

void del_at_end()
{
    printf("\nDeleting at end.\n");
    temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    tail=temp;
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
int main()
{
    insert();
    display();
    // del_at_start();
    del_at_end();
    display();
}