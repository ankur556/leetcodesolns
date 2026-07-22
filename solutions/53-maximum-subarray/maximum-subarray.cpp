class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int l=0;
        // int r=0;
        // int lsum=0;
        // int rsum=0;
        int n = nums.size();
        int cSum=0;
        int gSum = INT_MIN;
        for(int i= 0; i<n ; i++){
            cSum = max(nums[i], cSum+nums[i]);
            gSum = max(gSum, cSum);
        }

        return gSum;
    }
};