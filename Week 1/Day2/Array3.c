// Question:
// Write a C program to:

// Initialize an array with 5 elements: {1, 2, 3, 4, 5}.

// Reverse the array in-place using the two-pointer technique (without using any extra array).

// Print the reversed array.


// Two-Pointer Technique Explanation:
// The two-pointer technique is a common algorithmic approach used when you want to process data from both ends of a structure (like an array).


// In this code:

// int left = 0;
// int right = size - 1;
// Two pointers are initialized:

// left starts from the beginning of the array.

// right starts from the end.

// While loop:
// while (left < right) {
//     int temp = arr[left];
//     arr[left] = arr[right];
//     arr[right] = temp;
//     left++;
//     right--;
// }
// The elements at left and right are swapped.

// After each swap:

// left moves rightward (left++)

// right moves leftward (right--)

// This continues until they meet, fully reversing the array in-place.


#include<stdio.h>
void main(){
    int arr[5]={1,2,3,4,5},size,i;
    size=sizeof(arr)/sizeof(arr[0]);
    int left=0,right=size-1;
    while (left<right){
        int temp=arr[left];
        arr[left]=arr[right];
        arr[right]=temp;
        left++;
        right--;
    }
    printf("Elements in the arr: ");
    for (i=0;i<5;i++){
        printf("%d",arr[i]);
    }
    
}