class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<vector<vector<int>>> a;
        int n = mat.size();
        
        // 0 degrees
        //a.push_back(mat); 
        if(mat==target){return true;}
        // Block 1: 90 degrees (Transpose + Horizontal flip)
        for(int i = 0; i < n; i++) { for(int j = i + 1; j < n; j++) { swap(mat[i][j], mat[j][i]); } }
        for(int i = 0; i < n; i++) { for(int j = 0; j < n / 2; j++) { swap(mat[i][j], mat[i][n - 1 - j]); } }
        //a.push_back(mat);
        if(mat==target){return true;}
        // Block 2: 180 degrees (Rotate the 90 degree matrix again)
        for(int i = 0; i < n; i++) { for(int j = i + 1; j < n; j++) { swap(mat[i][j], mat[j][i]); } }
        for(int i = 0; i < n; i++) { for(int j = 0; j < n / 2; j++) { swap(mat[i][j], mat[i][n - 1 - j]); } }
        //a.push_back(mat);
        if(mat==target){return true;}
        // Block 3: 270 degrees (Rotate the 180 degree matrix again)
        for(int i = 0; i < n; i++) { for(int j = i + 1; j < n; j++) { swap(mat[i][j], mat[j][i]); } }
        for(int i = 0; i < n; i++) { for(int j = 0; j < n / 2; j++) { swap(mat[i][j], mat[i][n - 1 - j]); } }
        //a.push_back(mat);
        if(mat==target){return true;}
        return false;
        // Check all 4 stored matrices
        //bool sol = false;
        //for(int i = 0; i < a.size(); i++) {
        //    if(a[i] == target) {
        //        sol = true;
         //   }
        //}
        //return sol;
    }
};
