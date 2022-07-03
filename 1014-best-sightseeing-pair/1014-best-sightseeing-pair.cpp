class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int mx = 0, value = values[0], idx = 0;
        
        for(int i=1;i<values.size();i++){
            mx = max(mx,value+values[i] + idx - i);
            if((value-values[i])<=(i-idx))
                idx=i, value = values[i];
        }
        return mx;
    }
};