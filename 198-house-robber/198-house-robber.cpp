class Solution {
public:
    int rob(vector<int>& nums) {
      int dp[101];
      memset(dp, -1, sizeof(dp));
        
      return getMoney(nums, 0, dp);
    }
    int getMoney(vector<int>& nums, int n, int dp[]){
        if(n>=nums.size())
            return 0;
        
        int &r = dp[n];
        if(r != -1)
            return r;
        
        return r = max(getMoney(nums, n+1, dp), getMoney(nums, n+2, dp) + nums[n]);
    }
};