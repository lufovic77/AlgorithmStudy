dp = [[0 for col in range(110)] for row in range(110)]
def combi (n, r):
    if(dp[n][r]!=0):
	return int(dp[n][r]);
    if(n==r):
    	return int(1);
    dp[n][r] = int(int(combi(n-1, r-1)) + int(combi(n-1, r)))
    return int(dp[n][r])
#n,r = map(int,input().split(" "))
n, r = raw_input().split(" ")
n = int(n)
r = int(r)
for i in range(101):
    dp[i][1] = i;
ans = combi(n, r);
print(ans);
