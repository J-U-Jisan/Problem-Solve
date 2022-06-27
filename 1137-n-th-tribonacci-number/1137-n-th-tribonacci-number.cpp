class Solution {
public:
    int tribonacci(int n) {
        int dp[38];
        memset(dp, -1, sizeof(dp));
        
        return tribonacci(n, dp);
    }
    int tribonacci(int n, int dp[]){
        if(n==0||n==1)
            return n;
        if(n==2)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = tribonacci(n-1, dp) + tribonacci(n-2, dp) + tribonacci(n-3, dp);
    }
};