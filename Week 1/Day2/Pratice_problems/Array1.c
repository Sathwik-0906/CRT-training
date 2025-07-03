// Write a C program to:

// Declare and initialize an array of 5 integers: {1, 2, 3, 4, 5}.

// Calculate the sum of all the elements in the array.

// Calculate the average of the array elements.

// Print both the sum and the average with two decimal places.

#include<stdio.h>
void main(){
	int arr[5]={1,2,3,4,5};
    int sum=0,size,i;
    float avg;
    size=sizeof(arr)/sizeof(arr[0]);
    for(i=0;i<size;i++){
        sum+=arr[i];
    }
    printf("sum : %d",sum);
    avg=sum/size;
    printf("avg : %.2f",avg);
}