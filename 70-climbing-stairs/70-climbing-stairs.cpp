class Solution {
    
public:
    int climbStairs(int n) {
        int dp[46];
        memset(dp, -1 , sizeof(dp));
        return noOfWays(n,dp);
    }
    int noOfWays(int n, int dp[]){
        if(n<0) return 0;
        if(n==0)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = noOfWays(n-1, dp) + noOfWays(n-2, dp);
    }
};