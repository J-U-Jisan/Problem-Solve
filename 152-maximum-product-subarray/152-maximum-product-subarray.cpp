class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int rightNeg[n+1];
        rightNeg[n-1] = nums.back()<0?1:0;
        int leftNeg[n+1];
        leftNeg[0] = nums[0]<0?1:0;
        for(int i=n-2;i>=0;i--){
            rightNeg[i] = rightNeg[i+1] + (nums[i]<0?1:0);
            if(nums[i]==0)
                rightNeg[i] = 0;
        }
       for(int i=1;i<n;i++){
           leftNeg[i] = leftNeg[i-1] + (nums[i]<0?1:0);
       }
        int pre = nums[0], mx = nums[0], cur;
        for(int i=1;i<n;i++){
            cur = nums[i];
            if((pre<0 && rightNeg[i])|| pre>0){
                cur*=pre;
            }
            
            pre = cur;
            mx = max(mx, cur);
        }
        pre = nums[n-1];
        mx = max(mx, pre);
        for(int i=n-2;i>=0;i--){
            cur = nums[i];
            if((pre<0 && leftNeg[i]) || pre>0)
                cur*=pre;
            
            pre = cur;
            mx = max(mx, cur);
        }
        return mx;
    }
};