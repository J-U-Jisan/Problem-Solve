public class Solution {   
    
    public int LongestCommonSubsequence(string text1, string text2) {
        int[,] dp = new int[1002, 1002];
        int n = text1.Length;
        int m = text2.Length;
        for(int i=0;i<=n;i++){
            dp[i, m] = 0;
        }
        for(int i=0;i<=m;i++){
            dp[n, i] = 0;
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(text1[i] == text2[j])
                    dp[i, j] = dp[i+1, j+1]  + 1;
                else
                    dp[i, j] = Math.Max(dp[i, j+1], dp[i+1, j]);
            }
        }
        
        return dp[0,0];
    }
}