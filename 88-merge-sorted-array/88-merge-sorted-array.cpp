class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int firstArray = 0, lastArray = 0;
        
        for(int i=m-1, j=m+n-1;i>=0;i--,j--){
            nums1[j] = nums1[i];
        }
        int mainArray=0;
          
        while(firstArray<m && lastArray<n){
            if(nums1[firstArray+n]<nums2[lastArray]){
                nums1[mainArray] = nums1[firstArray+n];
                firstArray++;
            }
            else{
                nums1[mainArray] = nums2[lastArray];
                lastArray++;
            }
            mainArray++;
        }
        while(lastArray<n){
            nums1[mainArray++] = nums2[lastArray++];
        }
    }
};