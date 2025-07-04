#include<stdio.h>
void main()
{
    int arr[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int top=0,bot=4-1,left=0,right=4-1,i;
    while((top<=bot) && (left<=right))
    {
        for(i=left;i<=right;i++)
    {
        printf("%d ",arr[top][i]);
    }
    top+=1;
    
    for(i=top;i<=bot;i++)
    {
        printf("%d ",arr[i][bot]);
    }
    right-=1;
    
    for(i=right;i>=left;i--)
    {
        printf("%d ",arr[bot][i]);
    }
    bot-=1;
    
    for(i=bot;i>=top;i--)
    {
        printf("%d ",arr[i][left]);
    }
    left+=1;
    }
}


// spiral matrcix :
// input :
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16

// output: 1 2 3 4 8 12 16 15 14 13 9 10 5 6 7 11 10