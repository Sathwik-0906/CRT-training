// Question:
// "Write a C program to count the frequency of elements in an integer array and identify which elements are duplicates and which are unique."

// Input:
// An array of integers (e.g., {1, 2, 3, 4, 1, 2})

// Output:
// Display each number with its frequency.

// Print all elements that appear more than once as duplicates.

// Print all elements that appear exactly once as unique.

// Example Output:
// pgsql
// Copy
// Edit
// 1 : 2  
// 2 : 2  
// 3 : 1  
// 4 : 1  

// 1 is duplicate  
// 2 is duplicate  

// 3 is unique  
// 4 is unique  
#include <stdio.h>

int main() {
    int arr[6]={1,2,3,4,1,2},f[100]={},i;
    for(i =0;i<6;i++)
    {
        f[arr[i]]++;
    }
    for(i=0;i<100;i++){
        if(f[i]>0)
        {
            printf("%d : %d\n",i,f[i]);
        }
    }
    
    for(i=0;i<100;i++)
    {
        if(f[i]>1)
        {
            printf("%d is duplicate\n",i);
        }
    }
    
    for(i=0;i<100;i++)
    {
        if(f[i]==1)
        {
            printf("%d is unique\n",i);
        }
    }
}