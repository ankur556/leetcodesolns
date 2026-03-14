class Solution {
public:
    vector<int> fxn(int  n, vector<vector<int>>& dp) {
        if(dp[n].size()!=0){return dp[n];}
        vector<int> prev=fxn(n-1,dp);
        vector<int> curr=prev;
        int add=1<<(n-1);
        for(int i=prev.size()-1;i>=0;i--){
            curr.push_back(prev[i]|add);
        }
        return dp[n]=curr;
    }
    vector<int> grayCode(int n) {
        if(n==0){return {0};}
        vector<vector<int>> dp(n+1);
        dp[1].push_back(0);
        dp[1].push_back(1);
        return fxn(n,dp);
    }
};
