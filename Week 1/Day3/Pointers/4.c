def auto(n):
    arr=[]
    for i in n:
        arr.append(int(i))
    f=1
    for i in range(len(arr)):
        if(arr[i]!=n.count(i)):
            f=0
            break
        
    if f==1:
        print(len(set(arr)))
    else:
        print("0")
        
    
n=input()
auto(n)