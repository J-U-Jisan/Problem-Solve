class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1)
            return 1;
        
        int ar[n+1];
        int l2=0,l3=0,l5=0;
        ar[0] = 1;
        for(int i=1;i<n;i++){
            ar[i] = min(ar[l2]*2, min(ar[l3]*3, ar[l5]*5));
            if(ar[i] == ar[l2]*2) l2++;
            if(ar[i] == ar[l3]*3) l3++;
            if(ar[i] == ar[l5]*5) l5++;
        }
        return ar[n-1];
    }
};