class Solution {
public:
    int dp[2502];
    int lengthOfLIS(vector<int>& nums) {
        for(int i=0;i<=nums.size();i++)
            dp[i]=-1;
        int mx =0;
        for(int i=0;i<nums.size();i++){
            if(dp[i]==-1)
                mx = max(mx,getLIS(i, nums));    
        } 
        
        
        return mx;
    }
    int getLIS(int i, vector<int>& nums){
        if(i==nums.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=0;
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]<nums[j]){
                ans = max(ans,getLIS(j, nums));
            }
        }
        return dp[i] = ans+1;
    }
};