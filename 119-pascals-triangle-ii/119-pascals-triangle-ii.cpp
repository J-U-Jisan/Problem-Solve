class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>v;
        v.push_back(1);
        for(int j=1;j<=rowIndex;j++){
            int sz = v.size();
            int pre=1;
            for(int i=1;i<sz;i++){
                int temp = v[i];
                v[i] = v[i]+pre;
                pre = temp;
            }
            v.push_back(1);
        }
        
        return v;
    }
};