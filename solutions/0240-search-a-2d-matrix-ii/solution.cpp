class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            int u=lower_bound(matrix[i].begin(),matrix[i].end(),target)-matrix[i].begin();
            if(u<matrix[i].size()&&u>=0){
            if(matrix[i][u]==target){return true;}
            }
        }
        return false;
    }
};
