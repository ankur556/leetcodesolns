class Solution {
public:
     vector<vector<vector<int>>> dp;
    int helper(int i, int b, int tran, vector<int>& prices, int k){
        if(tran >=k or i>= prices.size()) {
           return 0;
        }
        if(dp[i][tran][b] !=-1) return  dp[i][tran][b];
        // 1 - b, 0 s
        if(b){
           int a = -prices[i] + helper(i+1, 0, tran, prices, k);
           int c = helper(i+1, 1, tran, prices, k);

            return dp[i][tran][b] = max(a, c);

        }else{
           int a = prices[i] + helper(i+1, 1 , tran+1, prices, k);
            int c = helper(i+1, 0, tran, prices, k);

             return dp[i][tran][b] = max(a,c);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

       dp.resize(n,vector<vector<int>>(k+1,vector<int>(2, -1)));
        helper(0,1,0,prices, k );

        return dp[0][0][1]; 
    }
};