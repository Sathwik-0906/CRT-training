#include<stdio.h>
void main(){
    int a[2][2],b[2][2],s[2][2],r,c;
    printf("Enter the A mat ele: \n");
    for(r=0;r<2;r++)
    {
        for(c=0;c<2;c++)
        {
            scanf("%d",&a[r][c]);
        }
    }

    printf("Enter the B mat ele: \n");
    for(r=0;r<2;r++)
    {
        for(c=0;c<2;c++)
        {
            scanf("%d",&b[r][c]);
        }
    }


    
    for(r=0;r<2;r++)
    {
        for(c=0;c<2;c++)
        {
            s[r][c]=a[r][c]+b[r][c];
        }
    }

    printf("Sum of A and B mat is :\n");
    for(r=0;r<2;r++)
    {
        for(c=0;c<2;c++)
        {
            printf("%d ",s[r][c]);
        }
        printf("\n");
    }
}