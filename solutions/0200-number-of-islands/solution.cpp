class Solution {
public:
    vector<pair<int,int>> dirs;
    void bfs(pair<int,int> a,vector<vector<char>>&grid,vector<vector<char>>&visited){
        queue<pair<int,int>> q;
        q.push(a);
        while(!q.empty()){
            pair<int,int> h=q.front();q.pop();
            if(visited[h.first][h.second]=='1'){}
            else{
            visited[h.first][h.second]='1';
            
            for(auto dir:dirs){
                int r=h.first;
                int c=h.second;
                int rc=r+dir.first;
                int cc=c+dir.second;
                if(rc>=0&&rc<grid.size()&&cc>=0&&cc<grid[0].size()&&visited[rc][cc]=='0'&&grid[rc][cc]=='1'){
                    q.push({rc,cc});
                }
            }}
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        dirs.push_back({1,0});
        dirs.push_back({-1,0});
        dirs.push_back({0,1});
        dirs.push_back({0,-1});
        vector<vector<char>> visited=grid;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){visited[i][j]='0';q.push({i,j});}
            }
        }
        int cnt=0;
    while(!q.empty()){
        pair<int,int>a=q.front();
        q.pop();
        if(visited[a.first][a.second]=='1'){}
        else{bfs(a,grid,visited);cnt++;}
    }
    return cnt;
    }
};
