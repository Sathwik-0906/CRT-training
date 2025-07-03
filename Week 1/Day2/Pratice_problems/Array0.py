
arr=[3,2,11,7,6,5,6,1]
n=len(arr)
b=[-1]*n
for i in range(0,len(arr)-1):
    for j in range(i+1,len(arr)):
        if arr[j]<arr[i]:
            b[i]=arr[j]
            break
print(b)
