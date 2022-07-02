class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int pre= nums[0], cur = 0, mx = nums[0];
        
        for(int i=1;i<nums.size();i ++){
            cur = nums[i] + (pre>0?pre: 0);
            mx = max(mx, cur);
            pre = cur;
        }
        int n = nums.size();
        int rightMax[n], rightSum[n];
        rightSum[n-1] = nums.back();
        for(int i=n-2;i>=0;i--){
            rightSum[i] = rightSum[i+1] + nums[i];
        }
        rightMax[n-1] = nums.back();
        for(int i = n-2;i>=0;i--){
            rightMax[i] = max(rightMax[i+1], rightSum[i]);
        }
        pre = 0;
        for(int i=0;i<(n-2);i++){
            pre+=nums[i];
            mx = max(mx, pre+rightMax[i+2]);
        }
        return mx;
    }
};