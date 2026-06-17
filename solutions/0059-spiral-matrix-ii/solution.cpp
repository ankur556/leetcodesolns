class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==1){vector<vector<int>>a;vector<int>b(1,1);a.push_back(b);return a;}
        vector<vector<int>> sol(n,vector<int>(n));
        int a=n*n;
        int d=0;
        vector<pair<int,int>>dirs={{0,1}, {1,0}, {0,-1}, {-1,0}};int cur_x=0;int cur_y=0;int x_d=0;int y_d=0;
        for(int i=0;i<a;i++){
            sol[cur_x][cur_y]=i+1;
            x_d=cur_x+dirs[d].first;y_d=cur_y+dirs[d].second;
            if(x_d < 0 || x_d >= n || y_d < 0 || y_d >= n || sol[x_d][y_d] != 0) {
                d = (d + 1) % 4; 
            }
             x_d=cur_x+dirs[d].first;y_d=cur_y+dirs[d].second;
             if(sol[x_d][y_d]!=0){d++;d%=4;}
            x_d=cur_x+dirs[d].first;y_d=cur_y+dirs[d].second;
            cur_x=x_d;cur_y=y_d;
        }
        return sol;
    }
};
