public class Solution {
    public bool IsAnagram(string s, string t) {
        char[] sc = s.ToCharArray();
        char[] tc = t.ToCharArray();
        
        Array.Sort(sc);
        Array.Sort(tc);
        s = new string(sc);
        t = new string(tc);
        
        if(s == t)
            return true;
        
        
        return false;
        
    }
}