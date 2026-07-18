class Solution {
public:
    int maximalRectangle(vector<vector<char>>& weights) {
        vector<vector<int>> matrix(weights.size(),vector<int>(weights[0].size()));
        for(int i=0;i<matrix.size();i++){
            int cur=0;
            for(int j=0;j<matrix[0].size();j++){
                if(weights[i][j]=='1'){cur++;}
                else{cur=0;}
                matrix[i][j]=cur;
            }
        }
        long long sol=0;
        for(int j=0;j<matrix[0].size();j++){
            vector<vector<int>> dp(matrix.size(),vector<int>(matrix.size(),1e9));
            for(int i=0;i<matrix.size();i++){
                dp[i][i]=matrix[i][j];
                if(dp[i][i]>sol){sol=dp[i][i];}
            }
            int cur=0;
            for(int diff=1;diff<matrix.size();diff++){
                for(int i=0;i<matrix.size()-diff;i++){
                    dp[i][i+diff]=min(dp[i][i+diff-1],dp[i+1][i+diff]);
                    if((diff+1)*dp[i][i+diff]>sol){sol=(diff+1)*dp[i][i+diff];}
                }
            }
        }
        return sol;
    }
};