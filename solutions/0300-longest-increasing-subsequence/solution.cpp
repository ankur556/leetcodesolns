class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,1);
        for(int i=0;i<n;++i){
            for(int j=i;j>=0;j--){
                if(nums[i]>nums[j]&&dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;}
            }
        }
        int max=0;
        for(int a: dp){if(a>max){max=a;}}
        return max;
    }
};
