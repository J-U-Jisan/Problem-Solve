class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int rightNeg[n+1];
        rightNeg[n-1] = nums.back()<0?1:0;
        for(int i=n-2;i>=0;i--){
            rightNeg[i] = rightNeg[i+1] + (nums[i]<0?1:0);
            if(!nums[i])
                rightNeg[i] = 0;
        }
        int leftNeg[n+1];
        leftNeg[0] = nums[0]<0?1:0;
        for(int i=1;i<n;i++){
            leftNeg[i] = leftNeg[i-1] + (nums[i]<0?1:0);
            if(nums[i]==0)
                leftNeg[i] = 0;
        }
        int l=0,mx=0, pre=1, cur;
        for(int i=0;i<n;i++){
            int b = nums[i]>0?nums[i]:(-nums[i]);
            if(!b)
                cur = 0;
            else
                cur = nums[i]/b;
            if(pre*cur>0 || (pre*cur<0 && rightNeg[i]>1)||(pre*cur<0 && cur>0 && rightNeg[i])){
                l++;
                cur*=pre;
            }
            else if(nums[i]>0)
                l=1;
            else{
                l=0;   
            }
            pre = cur;
            if(!pre)
                pre = 1;
            mx = max(mx,l);
        }
        l=0,pre=1;
        for(int i=n-1;i>=0;i--){
            int b = nums[i]>0?nums[i]:(-nums[i]);
            if(!b)
                cur = 0;
            else
                cur = nums[i]/b;
            if(pre*cur>0 || (pre*cur<0 && leftNeg[i]>1)||(pre*cur<0 && cur>0 && leftNeg[i])){
                l++;
                cur*=pre;
            }
            else if(nums[i]>0)
                l=1;
            else{
                l=0;   
            }
            pre = cur;
            if(!pre)
                pre = 1;
            mx = max(mx,l);
        }
        return mx;
    }
};