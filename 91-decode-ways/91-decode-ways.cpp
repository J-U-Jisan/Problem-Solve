class Solution {
public:
    int numDecodings(string s) {
        int dp[101];
        memset(dp, -1, sizeof(dp));
        if(s == "0")
            return 0;
        return numDecodings(s, 0, dp);
    }
    int numDecodings(string &s, int i, int dp[]){
        if(s.size() <= i)
            return 1;
        if(i>0 && s[i-1] == '0')
            return 0;
        int &rt = dp[i];
        if(rt != -1 )
            return rt;
        int a,b;
        a=b=0;
        if(i>0 && (s[i-1]=='1' || (s[i-1]=='2' && s[i]>='0' && s[i]<='6'))){
            if(!(i<s.size()-1 && s[i+1]=='0'))
                  a = numDecodings(s, i+2, dp);
        }
        if(s[i] != '0')
            b = numDecodings(s, i+1, dp);
        
        return rt = a+b;
    }
};