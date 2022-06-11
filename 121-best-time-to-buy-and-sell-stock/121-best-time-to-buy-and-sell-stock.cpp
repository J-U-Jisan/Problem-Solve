class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>m(prices.size());
        int ans=0;
        m[prices.size()-1]=prices.back();
        
        for(int i=prices.size()-2;i>=0;i--){
            m[i]=max(prices[i],m[i+1]);
        }
        for(int i=0;i<prices.size()-1;i++){
             ans=max(ans,m[i+1]-prices[i]);
        }
        return ans; 
    }
};