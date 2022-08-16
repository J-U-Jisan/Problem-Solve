class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> sum(mat.size(), vector<int>(mat[0].size())),ans(mat.size(), vector<int>(mat[0].size()));
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                sum[i][j] = mat[i][j] + (i>0?sum[i-1][j]:0) + (j>0?sum[i][j-1]:0) - (i>0 && j>0? sum[i-1][j-1]:0);
            }
        }
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                int r1=max(i-k,0), c1=max(j-k,0);
                int r2 = min(i+k, (int)mat.size()-1), c2 = min(j+k, (int)mat[i].size()-1);
         
                ans[i][j] = sum[r2][c2] - (c1>0?sum[r2][c1-1]:0) - (r1>0?sum[r1-1][c2]:0) + (c1>0 && r1>0 ? sum[r1-1][c1-1]:0);
            }
        }
        
        return ans;
    }
};