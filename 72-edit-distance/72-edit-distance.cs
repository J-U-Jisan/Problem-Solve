public class Solution {
    public int [,] dp = new int[502,502];
    public int lcs(int i, int j, ref string a, ref string b ){
        if(i == a.Length && j==b.Length)
            return 0;
        
        if(i == a.Length)
            return b.Length-j;
        if(j == b.Length)
            return a.Length-i;
        
        if(dp[i,j] != int.MaxValue)
            return dp[i,j];
        
        if(a[i] == b[j])
            dp[i,j] = lcs(i+1, j+1, ref a, ref b);
        else{
            int c = 1 + lcs(i + 1, j, ref a, ref b);
            int d = 1 + lcs(i+1, j+1, ref a, ref b);
            int e = 1 + lcs(i, j+1, ref a, ref b);
            dp[i,j] = Math.Min(c, Math.Min(d,e));
        }
        return dp[i,j];
    }
    public int MinDistance(string word1, string word2) {
        for(int i=0;i<word1.Length;i++){
            for(int j=0;j<word2.Length;j++){
                dp[i,j]=int.MaxValue;
            }
        }
        int b = lcs(0,0, ref word1, ref word2);
        Console.WriteLine(b);
        return b;
    }
}