#include<bits/stdc++.h>
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        dp[0]=0;
        for(int i=0;i<nums.size();i++){
            if(dp[i]>=0){
                for(int j=i;j<=nums.size()-1&&j<=i+nums[i];j++){
                    if(dp[j]==-1){dp[j]=dp[i]+1;}
                    if(dp[i]+1<dp[j]){dp[j]=dp[i]+1;}
                }
            }
        }
        return dp[dp.size()-1];
    }
};
