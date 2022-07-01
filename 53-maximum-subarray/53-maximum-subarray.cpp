class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre= nums[0], cur = 0, mx = nums[0];
        
        for(int i=1;i<nums.size();i++){
            cur = nums[i] + (pre>0?pre: 0);
            mx = max(mx, cur);
            pre = cur;
        }
        return mx;
    }

};