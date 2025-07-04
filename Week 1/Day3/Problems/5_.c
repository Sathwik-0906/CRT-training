#include<stdio.h>
void main()
{
    int arr[][3]={{1,2,3},{4,5,6},{7,8,9}};
    int sum=0;
    for(int i=0;i<3;i++)
    {
 
        for(int j=0;j<3;j++)
        {
            if(j<=i)
            {
                
                sum+=arr[i][j];
                
            }
        
        }
        
    }
    printf("%d",sum);
}

// input:
// 1 2 3
// 4 5 6
// 7 8 9
// sum of lower left triangle 1 + 4+ 5+ 7+ 8+ 9 = 34
// sum = 34