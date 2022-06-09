class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int gMax, cMax;
        gMax = cMax = nums[0];
        for(int i= 1;i<nums.size();i++){
            cMax = max(nums[i], cMax + nums[i]);
            gMax = max(cMax, gMax);
        }
        return gMax;
    }
};