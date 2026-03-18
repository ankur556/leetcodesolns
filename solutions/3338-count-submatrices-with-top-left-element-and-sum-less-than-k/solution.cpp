class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        vector<vector<int>> hsq=grid;
        //vector<vector<int>> vsq=grid;
        for(int i=1;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                hsq[i][j]+=hsq[i-1][j];
            }
        }
        for(int j=1;j<grid[0].size();j++){
            for(int i=0;i<grid.size();i++){
                hsq[i][j]+=hsq[i][j-1];
            }
        }
        int sol=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(hsq[i][j]<=k){sol++;}
            }
        }
        return sol;
    }
};
