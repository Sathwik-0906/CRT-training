def merged(left,right):
    i=j=0
    ans=[]
    while (i<len(left)) and (j<len(right)):
        if left[i]<right[j]:
            ans.append(left[i])
            i+=1
        else:
            ans.append(right[j])
            j+=1
    
    d=ans+left[i:]+right[j:]
    return d
    
def divs(l):
    if(len(l)==1):
        return l
    else:
        m=len(l)//2
        left=divs(l[:m])
        right=divs(l[m:])
    return merged(left,right)


l=[60,40,30,50,10,20]
print(l)
res=divs(l)
print(res)
    

    
