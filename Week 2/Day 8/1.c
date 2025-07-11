#include<stdio.h>
void sel(int l[], int n)
{
    int i ,j, mi, t;
    for(i=0;i<n;i=i+1)
    {
        mi=100; // assuming the minimum element is 100
        for(j=i;j<n;j=j+1)  
        {
            if(l[j]<mi)
            {
                mi=l[j]; // update minimum element
                t=j; // store the index of minimum element
            }
            t=l[i];
            l[i]=l[mi]
            l[mi]=t;
        }
    }
}


void main(){
    int a[] = {5,3,8,6,7,2};
    int size, i;
    size = sizeof(a)/sizeof(a[0]);
    printf("Unsorted array: ");
    for(i=0;i<size;i++){
        printf("%d ", a[i]);
        bs(a, size);
        printf("\nSorted array: ");
        for(i=0;i<size;i++){
            printf("%d ", a[i]);
        }
    }

}