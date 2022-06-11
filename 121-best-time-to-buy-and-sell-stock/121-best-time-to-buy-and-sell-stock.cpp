class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,mn=INT_MAX,mx=0;
        for(int i=prices.size()-2,j=prices.size()-1;i>=0;i--,j--){
            
            mx=max(mx,prices[j]);
            ans=max(ans,mx-prices[i]);
        }
        return ans; 
    }
};
























