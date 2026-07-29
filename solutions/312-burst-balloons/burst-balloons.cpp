class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),0));
        int n=dp.size();
        for (int len = 1; len <= n - 2; ++len) {
            for (int i = 1; i <= n - len - 1; ++i) {
                int j = i + len - 1;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j], 
                                   dp[i][k - 1] + nums[i - 1] * nums[k] * nums[j + 1] + dp[k + 1][j]);
                }
            }
        }
        int sol=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                sol=max(sol,dp[i][j]);
            }
        }
        return sol;
    }
};