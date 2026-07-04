class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<pair<int,int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
        int y=matrix.size();
        if(y==0){y=1;}
        else{y=matrix[0].size();}
        int stx=0;
        int sty=0;
        vector<int> sol;
        int cur_dir=0;
        vector<vector<int>> vis(matrix.size(),vector<int>(matrix[0].size()));
        int n=matrix.size()*matrix[0].size();
        for(int i=0;i<n;i++){
                vis[stx][sty]=1;
                sol.push_back(matrix[stx][sty]);
                int dx=stx+dirs[cur_dir].first;int dy=sty+dirs[cur_dir].second;
                if((!(dx>=0&&dx<matrix.size()&&dy>=0&&dy<y))||vis[dx][dy]==1){cur_dir++;cur_dir%=4; dx=stx+dirs[cur_dir].first; dy=sty+dirs[cur_dir].second;}
                stx=dx;sty=dy;  
        }
        return sol;
    }
};
