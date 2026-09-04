class Solution {
public:
    vector<vector<int>> dirs={{0,1},{0,-1},{-1,0},{1,0}};
    void bfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int x,int y){
        queue<pair<int,int>> q;
        q.push({x,y});
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(vis[i][j]==0){
                vis[i][j]=1;
                for(auto a : dirs){
                    int xd=i+a[0];
                    int yd=j+a[1];
                    if(xd<grid.size()&&xd>=0&&yd>=0&&yd<grid[0].size()&&grid[xd][yd]=='1'){q.push({xd,yd});}
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
      int sol=0;
      int n=grid.size();int m=grid[0].size();
      queue<pair<int,int>> q;
      vector<vector<int>> vis(n,vector<int>(m));
      for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]=='1'){q.push({i,j});}
        }
      }  
      while(!q.empty()){
        int i=q.front().first;int j=q.front().second;
        q.pop();
        if(vis[i][j]==0){
            sol++;
            bfs(grid,vis,i,j);
            vis[i][j]=1;
        }
      }
      return sol;
    }
};