class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<bool> bl(mat.size(),true);
        for(int i=0;i<mat.size();i++){
         for(int j=k;j<mat[i].size()+k;j++){
            if(mat[i][j%mat[i].size()]!=mat[i][(j-k)%mat[i].size()]){return false;}
         }
        }
        return true;
    }
};
