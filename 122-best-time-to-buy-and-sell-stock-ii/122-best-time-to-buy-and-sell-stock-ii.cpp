class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int a=prices[0];
        for(int i=1;i<prices.size();i++){
            if(a<prices[i]){
                ans+=(prices[i]-a);
                a = prices[i];
            }
            else{
                a = min(a, prices[i]);
            }
        }
        return ans;
    }
};