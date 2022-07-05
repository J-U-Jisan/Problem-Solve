class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int dp[301][301];
        memset(dp,-1,sizeof(dp));
        unordered_map<string,bool>mp;
        for(int i=0;i<wordDict.size();i++){
            mp[wordDict[i]]=true;
        }
        return wordBreak(s,0,0,mp,dp);
    }
    bool wordBreak(string s, int f, int l, unordered_map<string, bool>& mp, int dp[][301]){
        
        if(s.size()==l){
            string temp = s.substr(f, l-f+1);
            if(mp.find(temp) != mp.end())
                return true;
            else 
                return false;
        }
        
        int &rt = dp[f][l];
        if(rt !=-1)
            return rt;
        
        string temp = s.substr(f, l-f+1);
        bool a,b;
        a=b=false;
        if(mp.find(temp) != mp.end())
            a = wordBreak(s, l+1, l+1, mp, dp);
        b= wordBreak(s, f, l+1, mp, dp);
        
        return rt = a|b;
    }
};