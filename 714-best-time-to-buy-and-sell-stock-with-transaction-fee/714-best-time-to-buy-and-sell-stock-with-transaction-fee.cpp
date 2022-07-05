class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int dp[2][2];
        memset(dp,0,sizeof(dp));
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<2;j++){
                int ans1 = dp[(i+1)%2][j];
                    
                int ans2=(j==1?(-prices[i]-fee):prices[i])+dp[(i+1)%2][!j];
           
                dp[i%2][j] = max(ans2,ans1);
            }
        }
        return dp[0][1];
    }
};