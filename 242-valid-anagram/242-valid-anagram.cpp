class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[26]={0};
        for(char ch:s){
            cnt[ch-'a']++;
        }
        for(char ch:t){
            if(cnt[ch-'a']--<=0)
                return false;
        }
        for(int i:cnt){
            if(i)
                return false;
        }
        return true;
    }
};