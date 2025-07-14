def Findcount(arr,length,num,diff):
    count=0
    for i in range(length):
        c=num-arr[i]
        if abs(c) <= diff:
            count+=1
    return count
arr=[12,3,14,56,77,13]
length=int(input())
num=int(input())
diff=int(input())
sum=Findcount(arr,length,num,diff)
print("count",sum)
