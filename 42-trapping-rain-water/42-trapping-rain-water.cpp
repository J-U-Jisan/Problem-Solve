class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==1)
            return 0;
        
        int i=0, j=1,sum=0, ans=0, rightMax[n+1], maxIdx[n+1], rightSum[n+1];
        rightMax[n-1] = height[n-1];
        rightSum[n-1] = height[n-1];
        maxIdx[n-1] = n-1;
        for(int i=n-2;i>=0;i--){
            if(rightMax[i+1]<height[i]){
                rightMax[i] = height[i];
                maxIdx[i] = i;
            }
            else{
                rightMax[i] = rightMax[i+1];
                maxIdx[i] = maxIdx[i+1];
            }
            rightSum[i] = rightSum[i+1] + height[i];
        }
    
        for(;j<n;){
            if(height[i]<=rightMax[j]){
                if(height[i]<=height[j]){
                    ans+=max(height[i]*(j-i-1)-sum,0);
                    sum=0;
                    i=j;
                }
                else{
                    sum+=height[j];
                }
                j++;
            }
            else{
                
                int b = max(rightMax[j]*(maxIdx[j]-i-1) - (rightSum[i]-rightSum[maxIdx[j]]-height[i]),0);
                
                ans+=b;
                i=maxIdx[j];
                j=i+1;
                sum=0;
            }      
        }
        return ans;
        
    }
};