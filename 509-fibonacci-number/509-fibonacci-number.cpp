class Solution {
public:
    int fib(int n) {
        int dp[32];
        memset(dp, -1, sizeof(dp));
        return fibo(n, dp);
    }
    int fibo(int n, int dp[]){
        if(n==0||n==1)
            return n;
        
        if(dp[n]!=-1)
            return dp[n];
        
        return dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
    }
};