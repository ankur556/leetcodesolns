class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> sol;
        int row_begin=0;
        int row_end=matrix[0].size()-1;
        int col_begin=0;
        int col_end=matrix.size()-1;
        
        while(row_begin<=row_end && col_begin<=col_end){
            for(int i=row_begin;i<=row_end;i++){sol.push_back(matrix[col_begin][i]);}
            col_begin++;
            for(int i=col_begin;i<=col_end;i++){sol.push_back(matrix[i][row_end]);}
            row_end--;
            if(col_begin<=col_end){
            for(int i=row_end;i>=row_begin;i--){sol.push_back(matrix[col_end][i]);}
            col_end--;}
            if(row_begin<=row_end){
            for(int i=col_end;i>=col_begin;i--){sol.push_back(matrix[i][row_begin]);}
            row_begin++;}
        }
        return sol;

    }
};
