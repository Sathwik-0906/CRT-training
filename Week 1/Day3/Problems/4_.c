#include<stdio.h>
void main(){
    int arr[][3]={{10,20,30},{40,50,60},{70,80,90}};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(j>i)
            {
                
                printf("0 ");
                
            }
            else
            {
                printf("%d ",arr[i][j]);
            }
        }
        printf("\n");
    }
}



// input:
// 10 20 30
// 40 50 60
// 70 80 90

// output:
// 10 0 0 
// 40 50 0 
// 70 80 90 