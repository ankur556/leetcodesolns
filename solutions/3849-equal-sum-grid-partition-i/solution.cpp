class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& g) {
        vector<vector<long long>>grid;
        for(int i=0;i<g.size();i++){
            vector<long long> a;grid.push_back(a);
            for(int j=0;j<g[0].size();j++){
                grid[i].push_back(g[i][j]);
            }
        }
        long long sum=0;
        for(int i=0;i<grid.size();i++){for(int j=0;j<grid[0].size();j++){sum+=grid[i][j];}}
        if (sum % 2 != 0) return false;
        for(int i=1;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                grid[i][j]+=grid[i-1][j];
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=1;j<grid[0].size();j++){
                grid[i][j]+=grid[i][j-1];
            }
        }
        bool sol=false;
        for(int i=0;i<grid.size();i++){if(grid[i][grid[0].size()-1]==sum/2){return true;}}
        for(int i=0;i<grid[0].size();i++){if(grid[grid.size()-1][i]==sum/2){return true;}}
        return false;
    }
};
