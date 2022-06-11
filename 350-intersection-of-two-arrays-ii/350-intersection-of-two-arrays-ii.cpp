class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m2;
        
        for(int x:nums2){
            m2[x]++;
        }
        nums2.clear();
        for(int x:nums1){
            if(m2.find(x)!= m2.end() && m2[x]){
                nums2.push_back(x);
                m2[x]--;
            }
        }
        return nums2;
    }
};