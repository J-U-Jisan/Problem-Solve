class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>v[34];
        v[0].push_back(1);
        for(int j=1;j<=rowIndex;j++){
            v[j].push_back(1);
            for(int i=1;i<v[j-1].size();i++){
                v[j].push_back(v[j-1][i-1]+v[j-1][i]);
            }
            v[j].push_back(1);
        }
        
        return v[rowIndex];
    }
};