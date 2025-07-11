#include<stdio.h>
void insert(int a[],int n)
{

    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 and temp<a[j])
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }
}

void main(){
    int a[] = {5,3,8,6,7,2};
    int size, i;
    size = sizeof(a)/sizeof(a[0]);
    printf("Unsorted array: ");
    for(i=0;i<size;i++){
        printf("%d ", a[i]);
        insert(a, size);
        printf("\nSorted array: ");
        for(i=0;i<size;i++){
            printf("%d ", a[i]);
        }
    }
}