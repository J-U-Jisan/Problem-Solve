class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26]={0};
        for(int i=0;i<magazine.size();i++){
            cnt[magazine[i]-'a']++;
        }
        for(int i=0;i<ransomNote.size();i++){
            if(!cnt[ransomNote[i]-'a'])
                return false;
            cnt[ransomNote[i]-'a']--;
        }
        return true;
    }
};