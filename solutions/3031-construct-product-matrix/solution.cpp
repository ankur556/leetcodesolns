class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        long long suffix=1;//,prefix=1;
        vector<vector<int>> sol(grid.size(),vector<int>(grid[0].size(),1));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                sol[i][j]=suffix%12345;
               suffix=(suffix*grid[i][j])%12345;
                suffix%=12345;
            }
        }
        suffix=1;
        for(int i=grid.size()-1;i>=0;i--){
            for(int j=grid[0].size()-1;j>=0;j--){
                sol[i][j] = (sol[i][j] * suffix) % 12345;
                suffix=(suffix*grid[i][j])%12345;
                suffix%=12345;
            }
        }
        return sol;
    }
};
