class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
         int sol=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                matrix[i][j]=matrix[i][j]-'0';if(matrix[i][j]==1){sol=1;}
            }
        }
       
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size()));
        dp[0][0]=matrix[0][0];
        for(int i=1;i<dp.size();i++){dp[i][0]=matrix[i][0]+dp[i-1][0];}
        for(int i=1;i<dp[0].size();i++){dp[0][i]=matrix[0][i]+dp[0][i-1];}
        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]+matrix[i][j]-dp[i-1][j-1];
            }
        }
        if(sol==0){return 0;}
        // till here correct idk whats going wrong here
        for(int diff=1;diff<=min(matrix.size(),matrix[0].size());diff++){
            for(int i=0;i<matrix.size()-diff;i++){
                for(int j=0;j<matrix[0].size()-diff;j++){
                   int sum = dp[i+diff][j+diff];
                    if (i > 0) sum -= dp[i-1][j+diff];
                    if (j > 0) sum -= dp[i+diff][j-1];
                    if (i > 0 && j > 0) sum += dp[i-1][j-1];
                    if(sum==(diff+1)*(diff+1)){sol=sum;}
                }
            }
        }
        return sol;
    }
};