class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> ver;
        int com=0;
        for(int i=0;i<mat[0].size();i++){
            com=0;
            for(int j=0;j<mat.size();j++){
                if(mat[j][i]==1){com++;}
            }
            ver.push_back(com);
        }
        int rp=0;
        int ones=0;
        int sol=0;
        for(int i=0;i<mat.size();i++){
            rp=0;ones=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){ones++;}
                if(mat[i][j]==1&&ver[j]==1){rp++;}
            }
            if(rp==1&&ones==1){sol++;}
        }
        return sol;
    }
};
