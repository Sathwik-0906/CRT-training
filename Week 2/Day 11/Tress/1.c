#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node* createnode(int d)
{
    struct node *temp =(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void inorder(struct node *root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}


void postorder(struct node *root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void preorder(struct node *root)
{
    if(root)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
        
    }
}
int height(struct node *root)
{
    int lh,rh;
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        lh=height(root->left);
        rh=height(root->right);
        if(lh>rh)
        {
            return 1+lh;
        }
        else
        {
            return 1+rh;
        }
    }
}


int size(struct node *root)
{
    
    if(root==NULL)
    {
        return 0;
    }
    return 1+size(root->left)+size(root->right);
}

void main()
{
    struct node *root;
    root=createnode(1);
    root->left=createnode(2);
    root->right=createnode(3);
    root->left->left=createnode(4);
    root->left->right=createnode(5);
    root->right->left=createnode(6);
    root->right->right=createnode(7);
    root->right->right->right=createnode(9);

    printf("postorder: ");
    postorder(root);
    printf("\n");

    printf("inorder: ");
    inorder(root);
    printf("\n");

    printf("preorder: ");
    preorder(root);

    int h=height(root);
    printf("\n");
    printf("height is : %d",h);
    printf("\n");

    int s=size(root);
    printf("size of the tree is: %d",s);
}

