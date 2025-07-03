def rarr(arr,k):
    size=len(arr)
    for i in range(size-k,len(arr)):
        print(arr[i])
    for i in range(k+1):
        print(arr[i])

    # for i in range(k,len(arr)):
    #     print(arr[i])             #output : 34512
    # for i in range(k):
    #     print(arr[i])


n=int(input())
arr=[1,2,3,4,5]
rotate=int(input())
sum=rarr(arr,rotate)

# 12345 ------> 54123 after two rotaions