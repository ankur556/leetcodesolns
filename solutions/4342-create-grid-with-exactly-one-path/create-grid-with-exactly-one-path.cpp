class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> sol(m,string(n,'#'));
        for(int i=0;i<m;i++){sol[i][0]='.';}
        for(int i=0;i<n;i++){sol[sol.size()-1][i]='.';}
        return sol;
    }
};