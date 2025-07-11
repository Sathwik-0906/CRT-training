n=['aabaaba','bbaabb','abbab','aaabbb','abbbbabbb']
c=0
for i in n:
    f=1
    if len(i)%2==0:
        f=0
    else:
        mid=len(i)//2
        center=i[mid]
        left=i[:mid]
        right=i[mid+1:]
        lc=left.count(center)
        rc=right.count(center)
        if(lc!=rc):
            f=0
    if f==1:
        c+=1
print(c)

    
    