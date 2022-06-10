class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        set < pair<int,int> > ms;
        for(int i=0;i<nums.size();i++){
            ms.insert(make_pair(nums[i],i));
        }
        auto it= ms.begin(), jt=ms.end();
        jt--;
        for(;it!=jt && it!=ms.end();){
            if(it->first+jt->first == target){
                return vector<int>{it->second, jt->second};
            }
            else if(it->first+jt->first>target)
                jt--;
            else it++;
        }
        return vector<int>();
    }
};