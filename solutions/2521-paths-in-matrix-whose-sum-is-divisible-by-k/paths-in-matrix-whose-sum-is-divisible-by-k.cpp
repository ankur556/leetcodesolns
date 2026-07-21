class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int mod=1e9+7;
        vector<vector<vector<long long>>> dp(grid.size(), vector<vector<long long>>(grid[0].size(), vector<long long>(k, 0)));
        dp[0][0][grid[0][0]%k]=1;
        for(int i=1;i<grid.size();i++){
            for(int j=0;j<k;j++){
                dp[i][0][j]+=dp[i-1][0][(((j-grid[i][0])%k)+k)%k];
            }
        }
        for(int i=1;i<grid[0].size();i++){
            for(int j=0;j<k;j++){
                dp[0][i][j]+=dp[0][i-1][((j-grid[0][i])%k+k)%k];
            }
        }
        //intialisation done
        for(int i=1;i<grid.size();i++){
            for(int j=1;j<grid[0].size();j++){
                for(int var=0;var<k;var++){
                   dp[i][j][var]=((
                    (dp[i][j-1][(var-grid[i][j]%k+k)%k])%mod+
                    (dp[i-1][j][(var-grid[i][j]%k+k)%k])%mod
                    )%mod+dp[i][j][var]%mod)%mod;
                }
            }
        }
        return dp[dp.size()-1][dp[0].size()-1][0];
    }
};