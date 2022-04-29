class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int a = nums[0], cnt=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == a)
                cnt=2;
            else if(cnt!=2){
                return a;
            }
            else{
                cnt=0;
                a = nums[i];
            }
        }

        return nums[nums.size()-1];
    }
};