class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>>dp=matrix;
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(j==0){dp[i][j]=matrix[i][j]+min(dp[i-1][j],dp[i-1][j+1]);}
                else if(j==matrix[0].size()-1){dp[i][j]=matrix[i][j]+min(dp[i-1][j-1],dp[i-1][j]);}
                else{dp[i][j]=matrix[i][j]+min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1]));}
            }
        }
        int sol=dp[dp.size()-1][0];
        for(int j=0;j<matrix.size();j++){
            if(dp[dp.size()-1][j]<sol){sol=dp[dp.size()-1][j];}
        }
        return sol;
    }
};
