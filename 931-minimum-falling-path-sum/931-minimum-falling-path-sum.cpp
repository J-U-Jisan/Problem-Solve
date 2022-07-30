class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
      
        int dp[n+1][101];
        memset(dp, -1, sizeof(dp));
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans, minFallingPathSum(matrix, 0,i, dp));
        }
        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix, int l, int r, int dp[][101]){
        if(l==matrix.size())
            return 0;
        
        int &rt = dp[l][r];
        if(rt != -1)
            return rt;
        
        int a,b,c;
        a=b=c=1e7;
        if(r>0)
            a = minFallingPathSum(matrix,l+1, r-1,dp);
        if(r<matrix.size()-1)
            b = minFallingPathSum(matrix,l+1, r+1, dp);
        
        c = minFallingPathSum(matrix, l+1, r, dp);
        
        return rt = matrix[l][r] + min(a,min(b,c));
    }
};