class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
        if(v.size()<3)
        return 0;

        int val = v[1]-v[0];
        int ans = 0, idx=0;
        for(int i=1;i<v.size()-1;i++){
            if(v[i+1]-v[i] != val){
                val = v[i+1]-v[i];
                int n = i-idx-1;

                ans += (n>0?(n*(n+1)/2):0);
                idx = i;
            }
        }
        if(idx+2<v.size())
        {
            int n = v.size()-idx-2;
            ans+= (n*(n+1)/2);
        }
        return ans;
    }
};