class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        vector<vector<bool>> ok(grid[0].size(),vector<bool>(grid[0].size()));
        for(int i=0;i<grid[0].size();i++){
            for(int j=i+1;j<grid[0].size();j++){
                bool v=true;
                for(int r=0;r<grid.size();r++){
                    if(abs(grid[r][j]-grid[r][i])>limit){v=false;break;}
                }
                ok[i][j]=v;
            }
        }
        vector<int> dp(grid[0].size(),1);
        int max=1;
        for(int i=0;i<dp.size();i++){
            for(int j=i+1;j<dp.size();j++){
            if(ok[i][j]){dp[j]=std::max(dp[j],dp[i]+1);}
                max=std::max(max,dp[j]);
            }
        }
        return max;
    }
};