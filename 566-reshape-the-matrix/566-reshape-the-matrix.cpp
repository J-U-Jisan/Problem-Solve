class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();

        if(m*n != r*c){
            return mat;
        }
        else{
            vector<vector<int>>v;
            vector<int>temp;
            int s;
            s=0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    temp.push_back(mat[i][j]);
                    s++;
                    if(s==c){
                        s=0;
                        v.push_back(temp);
                        temp.clear();
                    }
                }
            }
            return v;
        }
    }
};