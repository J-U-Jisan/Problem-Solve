public class Solution {
    public string DecodeString(string s) {
        Stack<char> st = new Stack<char>();
        Stack<int> cnt = new Stack<int>();
        int number = 0;
        for(int i=0;i<s.Length;i++){
            if(s[i]>='0' && s[i]<='9')
                number = number*10 + (s[i] - '0');
            else if(s[i] == ']'){
                StringBuilder temp = new StringBuilder();
                while(st.Peek() != '['){
                    temp.Append(st.Pop());
                }
                st.Pop();
                number = cnt.Pop();
                while(number>0){
                    number--;
                    for(int j = temp.Length-1; j>=0; j--){
                        st.Push(temp[j]);
                    }
                }
                number = 0;
            }
            else{
                if(number>0)
                    cnt.Push(number);
                number = 0;
                st.Push(s[i]);
            }
        }
        StringBuilder output = new StringBuilder();
        while(st.Count>0){
            output.Append(st.Pop());
        }
        
        for(int i = 0, j = output.Length - 1 ;i<j; i++,j--){
            char ch = output[i];
            output[i] = output[j];
            output[j] = ch;
        }
        
        return output.ToString();
    }
}