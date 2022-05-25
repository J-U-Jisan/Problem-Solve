public class Solution {
    public int[,] dp = new int[1002,1002];
    
    public int LCS(int i, int j, ref string a, ref string b){
        if(i==a.Length || j==b.Length)
            return 0;
        
        if(dp[i, j]!=-1)
            return dp[i, j];
        
        if(a[i] == b[j])
            dp[i, j] = 1 + LCS(i+1, j+1, ref a, ref b);
        
        else{
            dp[i, j] = Math.Max(LCS(i+1, j, ref a, ref b), LCS(i, j+1, ref a, ref  b));
        }
        return dp[i, j];
    }
    public int LongestCommonSubsequence(string text1, string text2) {
           for(int i=0;i<text1.Length;i++){
               for(int j=0;j<text2.Length;j++){
                   dp[i, j] = -1;
               }
           }
        
        return LCS(0, 0, ref text1, ref text2);
    }
}