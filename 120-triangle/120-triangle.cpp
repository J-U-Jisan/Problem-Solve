
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sz = triangle.size();
        vector<int>temp(triangle.back().begin(), triangle.back().end());
       
        for(int i=sz-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                
                temp[j] = triangle[i][j] + min(temp[j],temp[j+1]);
            }
        }
        
        return temp[0];
    }
};