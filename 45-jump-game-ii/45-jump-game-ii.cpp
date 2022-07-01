class Solution {
public:
    int jump(vector<int>& nums) {
        int dp[10003];
        memset(dp, -1, sizeof(dp));
        return jump(nums, 0, dp);
    }
    int jump(vector<int>&nums, int n, int dp[]){
        if(n>=nums.size()-1)
            return 0;
        if(nums[n]==0)
            return 1e8;
        
        int &rt = dp[n];
        if(rt !=-1 )
            return rt;
        
        int sz = min((int)nums.size(), n+nums[n] + 1);
        int ans = INT_MAX;
        for(int i=n+1;i<sz;i++){
            ans = min(ans, jump(nums, i, dp) + 1);
        }
        return rt = ans;
    }
};