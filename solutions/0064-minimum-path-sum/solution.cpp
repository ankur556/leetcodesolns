class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> helper=grid;
        for(int i=1;i<grid.size();i++){
            helper[i][0]+=helper[i-1][0];
        }
        for(int i=1;i<helper[0].size();i++){
            helper[0][i]+=helper[0][i-1];
        }
        for(int i=1;i<helper.size();i++){
            for(int j=1;j<helper[0].size();j++){
                helper[i][j]+=min(helper[i-1][j],helper[i][j-1]);
            }
        }
        return helper[helper.size()-1][helper[0].size()-1];
    }
};
