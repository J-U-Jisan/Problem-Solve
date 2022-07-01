class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dp[10003];
        memset(dp, -1, sizeof(dp));
        
        return canJump(nums, 0, dp);
    }
    bool canJump(vector<int>& nums, int n, int dp[]){
        if(n==nums.size()-1)
            return true;
        if(!nums[n])
            return false;
        int &rt = dp[n];
        if(rt!=-1)
            return rt;
        
        bool b = false;
        int sz = min((int)nums.size(), nums[n] + n+1);
        for(int i=n+1;i<sz;i++){
            b = b | canJump(nums,i,dp);
            if(b)
                break;
        }
        return rt = b;
    }
};