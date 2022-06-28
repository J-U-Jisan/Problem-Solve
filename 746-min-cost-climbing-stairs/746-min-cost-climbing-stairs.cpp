class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[1001];
        memset(dp, -1, sizeof(dp));
        
        return min(minCost(cost, dp, 0), minCost(cost, dp, 1));
    }
    
    int minCost(vector<int>&cost, int dp[], int n){
        if(n>=cost.size())
            return 0;
        
        if(dp[n] !=-1)
            return dp[n];
        
        return dp[n] = cost[n] + min(minCost(cost, dp, n+1), minCost(cost, dp, n+2));
    }
};