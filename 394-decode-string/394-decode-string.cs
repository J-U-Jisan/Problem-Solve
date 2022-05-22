public class Solution {
    public string DecodeString(string s) {
        Stack<char> st = new Stack<char>();
        Stack<int> k = new Stack<int>();
        int number = 0;
        string temp = "";
        foreach(var ch in s){
            if(ch>='0' && ch<='9'){
                number = number*10 + (ch-'0');
            }
            else if(ch == ']'){
                int repeat = k.Pop();
           
                while(st.Peek() != '['){
                    temp += st.Pop();
                }
                st.Pop();
                while(Convert.ToBoolean(repeat--)){
                    for(int i = temp.Length-1;i>=0;i--){
                        st.Push(temp[i]);
                    }
                }
                temp = "";
                
            }
            else{
                if(number >0 )
                    k.Push(number);
                number = 0;
                
                st.Push(ch);
            }
        }
        string output = "";
        while(st.Count > 0){
            output += st.Pop();
        }
        
        return new string(output.ToCharArray().Reverse().ToArray());
    }
}