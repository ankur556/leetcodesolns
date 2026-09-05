class Solution {
public:
    vector<pair<int,int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
    void bfs(vector<vector<char>> & grid,vector<vector<int>> & vis ,int x ,int y){
        queue<pair<int,int>> q1;
        q1.push({x,y});
        //vis[x][y]=1;
        while(!q1.empty()){
            int i=q1.front().first;
            int j=q1.front().second;
            q1.pop();
            if(vis[i][j]==0){
                vis[i][j]=1;
                for(auto a : dirs){
                    int d1=i+a.first;
                    int d2=j+a.second;
                    if(d1>=0&&d1<grid.size()&&d2>=0&&d2<grid[0].size()&&grid[d1][d2]=='1'){
                        if(vis[d1][d2]==0){q1.push({d1,d2});}
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int,int>> q;
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size()));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){q.push({i,j});}
            }
        }
        int sol=0;
        while(!q.empty()){
            int x=q.front().first;int y=q.front().second;
            q.pop();
            if(vis[x][y]==0){
                sol++;
                bfs(grid,vis,x,y);
                vis[x][y]=1;
            }
        }
        return sol;
    }
};