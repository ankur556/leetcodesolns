class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> map;
        int max=0;
        for(int i: nums){if(i>max){max=i;}map[i]++;}
        vector<pair<int,int>> dp(max+1,{0,0});
        for(int i=1;i<dp.size();i++){
            dp[i].first=dp[i-1].second+map[i]*i;
            dp[i].second=std::max(dp[i-1].first,dp[i-1].second);
        }
        return std::max(dp[dp.size()-1].first,dp[dp.size()-1].second);
    }
};