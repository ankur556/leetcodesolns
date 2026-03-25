class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        if(mat.size()==1){return mat[0][0];}
int s=0;
for(int i=0;i<mat.size();i++){s+=mat[i][i];}
for(int i=0;i<mat.size();i++){s+=mat[mat.size()-1-i][i];}
if(mat.size()%2==0){return s;}
else{return (s-mat[mat.size()/2][mat.size()/2]);}
    }
};
