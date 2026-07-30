class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // cost size<=1000
        if(cost.size()==0){return 0;}
        else if(cost.size()==1){return cost[0];}
        else if(cost.size()==2){return min(cost[0],cost[1]);}
        cost.push_back(0);
        vector<int> dp(cost.size());
        // if ur on a step climb 1 or 2 
        // dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        dp[0]=cost[0];
        dp[1]=cost[1];
        //cout<<1<<endl;
        for(int i=2;i<cost.size();i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return dp[dp.size()-1];
    }
};