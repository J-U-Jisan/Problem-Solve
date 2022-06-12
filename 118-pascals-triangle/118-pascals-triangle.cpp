class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>v;
        vector<int>temp;
        temp.push_back(1);
        v.push_back(temp);
        temp.clear();
        numRows--;
        int idx=0;
        while(numRows--){
            temp.push_back(1);
            for(int i=1;i<v[idx].size();i++){
                temp.push_back(v[idx][i-1]+v[idx][i]);
            }
            idx++;
            temp.push_back(1);
            v.push_back(temp);
            temp.clear();
        }
        return v;
    }
};