class Solution {
public:
    int mod;
    vector<vector<int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
    int bfs(vector<vector<int>> & grid,vector<vector<int>> & vis,int x,int y){
        queue<pair<int,int>> q;
        q.push({x,y});
        int ret=grid[x][y];
        vis[x][y]=1;
        while(!q.empty()){
            int x1=q.front().first;
            int y1=q.front().second;
            q.pop();
            for(auto a : dirs){
                int x2=x1+a[0];
                int y2=y1+a[1];
                if(x2>=0&&x2<grid.size()&&y2>=0&&y2<grid[0].size()&&vis[x2][y2]==0&&grid[x2][y2]>0){
                    ret=(grid[x2][y2]+ret)%mod;
                    vis[x2][y2]=1;
                    q.push({x2,y2});
                }
            }
        }
        return ret;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        mod=k;
        int sol=0;
        int n=grid.size();int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0&&grid[i][j]>0){
                    if(bfs(grid,vis,i,j)%k==0){sol++;}
                }
            }
        }
        return sol;
    }
};