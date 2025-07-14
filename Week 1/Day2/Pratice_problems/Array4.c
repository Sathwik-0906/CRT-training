// To find the sum of all "leader elements" in an array.

// 💡 What is a Leader in an Array?
// An element is called a leader if it is greater than or equal to all elements to its right.

// For example, in the array [52, 66, 64, 36, 45, 24, 32]:

// 66 is a leader (greater than all to its right)

// 64 is a leader

// 45 is a leader

// 32 is a leader

def leader(arr,n):
    s=0
    for i in range(n):
        flag=1
        for j in range(i+1,n):
            if arr[j]>arr[i]:
                flag=0
                break
        if flag==1:
            s+=arr[i]
    return 
    

n=7
arr=[52,66,64,36,45,24,32]
sum=leader(arr,n)
if sum==0:
    print(-1)
else:
    print(sum) //here the time complexity is o(n^2)


def leader_optimized(arr, n):
    max_from_right = arr[n - 1]
    s = max_from_right  # Last element is always a leader

    for i in range(n - 2, -1, -1):  # Traverse from second last to first
        if arr[i] >= max_from_right:
            s += arr[i]
            max_from_right = arr[i]
    return s

# Test
n = 7
arr = [52, 66, 64, 36, 45, 24, 32]
print(leader_optimized(arr, n))



    
