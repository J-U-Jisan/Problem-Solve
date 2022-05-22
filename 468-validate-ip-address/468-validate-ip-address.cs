public class Solution {
    public string ValidIPAddress(string queryIP) {
        string[] sIP = queryIP.Split('.');
        if(sIP.Length != 1 && sIP.Length != 4)
            return "Neither";
        else if(sIP.Length == 4){
            foreach(string s in sIP){
                if(s.Length == 0 || (s.Length>1 && s[0]=='0') || s.Length>3)
                    return "Neither";
                else{
                    int number = 0;
                    foreach(var ch in s){
                        if(ch>='0' && ch<='9'){
                            number = number*10 + ch - '0';
                        }
                        else
                            return "Neither";
                    }
                    if(number>255)
                        return "Neither";
                }
                
            }
            return "IPv4";
        }
        else{
            string[] ipv6 = queryIP.Split(':');
            if(ipv6.Length == 8 ){
                foreach(string s in ipv6){
                    if(s.Length>4 || s.Length==0)
                        return "Neither";
                    else{
                        foreach(var ch in s){
                            if(!((ch>='a' && ch<='f') || (ch>='A' && ch<='F') || (ch>='0' && ch<='9')))
                                return "Neither";
                        }
                    }
                }
                return "IPv6";
            }
            else{
                return "Neither";
            }
        }
    }
}