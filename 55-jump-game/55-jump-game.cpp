class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dp[10003];
        int b = 1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>=b)
                b=1;
            else
                b++;
        }
        if(b>1)
            return false;
        return true;
    }
   
};