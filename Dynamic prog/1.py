def feb(n):
    dp=[0]*(n+1)
    print(dp)
    dp[0]=0
    dp[1]=1 
    print(dp)
    for i in range(2,n+1):
        print(dp[i-1],dp[i-2])
        dp[i]=dp[i-1]+dp[i-2]
    return dp[n]


print(feb(5))