// Write a C program to:

// Declare and initialize an array of 5 integers: {12, 45, 2, 7, 8}.

// Print all the elements of the array.

// Find and print the maximum and minimum values in the array.

// Find and print the second maximum and second minimum values in the array (excluding the maximum and minimum themselves).

// ✳️ Assume all elements are distinct for simplicity.




#include<stdio.h>
void main(){
    int arr[5]={12,45,2,7,8};
    // printf("Enter the Number: ");
    // for(int i=0;i<5;i++){
    //     scanf("%d",&arr[i]);
    // }
    printf("The elements of the Array : ");
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    int max1=-32768,min1=32767;
    for (int i=0;i<5;i++)
    {
        if(arr[i]>max1){
            max1=arr[i];
        }
        if(arr[i]<min1){
            min1=arr[i];
        }
    }
    printf("Max value: %d and Min value: %d\n",max1,min1);
    
    int max2=-32768,min2=32767;
    for (int i=0;i<5;i++)
    {
        if(arr[i]>max2 && arr[i]!=max1) 
        {
            max2=arr[i];
        }
        if(arr[i]<min2 && arr[i]!=min1) 
        {
            min2=arr[i];
        }
    }
    printf("Max value: %d and Min value: %d\n",max2,min2);
    
}