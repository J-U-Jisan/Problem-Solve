class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[102][2];
        memset(dp,-1,sizeof(dp));
        return rob(nums, 0, 0, dp);
    }
private:
    int rob(vector<int>& nums, int n, int check, int dp[][2]){
        if(nums.size() <=n)
            return 0;
        int &rt = dp[n][check];
        if(rt != -1)
            return rt;
        
        int a = rob(nums, n+1, check, dp);
        int b = 0;
        if(n==0)
            check = 1;
        if(!check || n != nums.size()-1 || nums.size() == 1)
            b = rob(nums, n+2, check, dp) + nums[n];
        
        return rt = max(a,b);
    }
};