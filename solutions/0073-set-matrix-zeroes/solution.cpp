class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> a;
        vector<int> b;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){a.push_back(i);break;}
            }
        }
        for(int i=0;i<matrix[0].size();i++){
            for(int j=0;j<matrix.size();j++){
                if(matrix[j][i]==0){b.push_back(i);break;}
            }
        }
        for(int i=0;i<a.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                matrix[a[i]][j]=0;
            }
        }
        for(int i=0;i<b.size();i++){
            for(int j=0;j<matrix.size();j++){
                matrix[j][b[i]]=0;
            }
        }
    }
};
