arr=[30,31,32,34,35]
for i in range(0,len(arr)-1):
    if arr[i+1]!=arr[i]+1:
        print(arr[i]+1)
        break
    
#missing elements in the aaray [30,31,32,34,35] missing one is 33