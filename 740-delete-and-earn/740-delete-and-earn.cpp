class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mp[10004]={0};
        int mx = 0, mn = INT_MAX;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
        }
        int pre, cur;
        pre = cur = 0;
        for(int i=mn;i<=mx;i++){
            int temp = max(pre+i*mp[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};