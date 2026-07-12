class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,1e7);
        dp[0]=0;
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<dp.size();j++){
                dp[j]=min(dp[j-coins[i]]+1,dp[j]);
                //cout<<dp[j]<<" "<<j<<endl;
            }
        }
        if(dp[dp.size()-1]==1e7){return -1;}
        else{return dp[dp.size()-1];}
    }
};
