class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size()-1);
    }
private:
    int maxSubArray(vector<int>& nums, int l, int r){
        if(l>r)
            return INT_MIN;
        
        int m = (l+r)/2;
        int mr = 0, ml = 0;
        int lmax = maxSubArray(nums, l, m - 1);
        int rmax = maxSubArray(nums, m+1, r);
        
        for(int i=m-1, sum = 0; i>=l;i--){
            sum += nums[i];
            ml = max(ml, sum);
        }
        for(int i = m+1, sum = 0;i<=r;i++){
            sum += nums[i];
            mr = max(mr, sum);
        }
        
        return max(max(lmax, rmax), mr + ml + nums[m]);
    }
};