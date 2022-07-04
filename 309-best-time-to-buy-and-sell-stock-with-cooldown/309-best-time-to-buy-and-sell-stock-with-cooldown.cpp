class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp[5002][1001];
        memset(dp, -1,sizeof(dp));
        return maxProfit(prices, 0, prices[0], dp);
    }
    int maxProfit(vector<int>& prices, int n, int price, int dp[][1001]){
        if(n>=prices.size())
            return 0;
        int &rt = dp[n][price];
        if(rt != -1)
            return rt;
        if(prices[n]>price){
            rt = max(maxProfit(prices, n+1, price, dp),prices[n]-price + maxProfit(prices, n+2, (n+2<prices.size()?prices[n+2]:0), dp));
        }
        else{
            rt = maxProfit(prices, n+1, prices[n], dp);
        }
        return rt;
    }
};