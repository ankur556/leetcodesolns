class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> map;
        for(int i=0;i<matrix.size();i++){
             string s;
             for(int j=0;j<matrix[i].size();j++){s.push_back(matrix[i][j]+'0');}
            map[s]++;}
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                matrix[i][j]^=1;
            }
        }
        for(int i=0;i<matrix.size();i++){string s;
             for(int j=0;j<matrix[i].size();j++){s.push_back(matrix[i][j]+'0');}
            map[s]++;}
        int sol=0;
        for(int i=0;i<matrix.size();i++){string s;
             for(int j=0;j<matrix[i].size();j++){s.push_back(matrix[i][j]+'0');}
            if(map[s]>sol){sol=map[s];}}
        return sol;
    }
};