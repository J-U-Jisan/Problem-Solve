class Solution {
public:
    vector<int>temp;
    void rotate(vector<int>& nums, int k) {
        k%= nums.size();
        temp.insert(temp.begin(),nums.end()-k,nums.end());
        for(int i=0;i<nums.size()-k;i++){
            temp.push_back(nums[i]);
        }
        nums = temp;
        temp.clear();
    }
};