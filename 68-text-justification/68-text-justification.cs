public class Solution {
    public IList<string> FullJustify(string[] words, int maxWidth) {
        List<string> output = new List<string>();
        List<string> t = new List<string>();
        string temp = "";
        int sz = 0, padd, exPadd;
        foreach(var word in words){
  
            if(sz + word.Length + t.Count <= maxWidth){
                sz+=word.Length;
                t.Add(word);
                
            }
            else{
  
                int empt = maxWidth - sz;
                padd = empt;
                exPadd = 0;
                if(t.Count>1){
                    padd = empt/(t.Count-1);
                    exPadd = empt%(t.Count-1);
                }
                
                for(int i = 0;i+1<t.Count; i++){
                    temp+=t[i];
                    int cnt = padd;
                    while(cnt>0){
                        cnt--;
                        temp+=' ';
                    }
                    if(exPadd>0){
                        temp += ' ';
                        exPadd--;
                    }
                }
                temp += t[t.Count-1];
                if(t.Count==1){
                    while(Convert.ToBoolean(padd--)){
                        temp+=' ';
                    }
                }
                output.Add(temp);
                t.Clear();
                t.Add(word);
                sz=word.Length;
                temp = "";
            }
        }
        foreach(var st in t){
            temp += st + ' ';    
        }
        
        temp = temp.TrimEnd();
        padd = maxWidth - temp.Length;
      
        while(padd>0){
            padd--;
            temp+=' ';
        }
        output.Add(temp);
        
        return output;
    }
}