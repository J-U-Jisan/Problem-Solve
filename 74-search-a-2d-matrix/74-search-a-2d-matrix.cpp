class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int total = m*n;
        int left=0,right=total-1;
        while(left<=right){
            int mid = (left+right)/2;
            int i = mid/n;
            int j = mid%n;
            if(matrix[i][j]==target)
                return true;
            else if(matrix[i][j]>target)
                right = mid-1;
            else left = mid+1;
        }
        return false;
    }
};