class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        if(amount==0){return 0;}
        dp[0]=0;
        bool p=false;
        for(int i: coins){if(i<amount){p=true;break;}if(i==amount){return 1;}}
        if(!p){return -1;}
        for(int i=0;i<coins.size();i++){
            if(coins[i]<amount){
            dp[coins[i]]=1;}
        }
        for(long long i=0;i<coins.size();i++){
            for(long long j=0;j<=amount;j++){
                if(j+coins[i]<=amount){
                if(dp[j+coins[i]]==-1&&dp[j]!=-1){dp[j+coins[i]]=dp[j]+1;}
                if(dp[j+coins[i]]>dp[j]+1&&dp[j]!=-1){dp[j+coins[i]]=dp[j]+1;}}
            }
        }
        return dp[amount];
    }
};
