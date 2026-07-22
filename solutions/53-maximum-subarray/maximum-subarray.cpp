class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int l=0;
        // int r=0;
        // int lsum=0;
        // int rsum=0;
        int n = nums.size();
        int cSum=nums[0];
        int gSum = nums[0];
        /// 9 -1 12  => 11 12+8 => 20
        for(int i= 1; i<n ; i++){
                if(cSum + nums[i] < nums[i]) cSum = nums[i];
                else cSum += nums[i];
            gSum= max( gSum, cSum);
        }

        return gSum;
    }
};