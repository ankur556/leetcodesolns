class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> a(m,string(n, '.'));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==m-1){a[i][j]='.';}
                else if(j==0){a[i][j]='.';}
                else{a[i][j]='#';}
            }
        }
        return a;
    }
};
