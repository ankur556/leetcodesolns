class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int init=0;
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size()));
        queue<pair<int,pair<int,int>>> q;
        int sol=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
               if(grid[i][j]==2){ 
                q.push({0,{i,j}});}
                else if(grid[i][j]==1){
                    init++;
                }
            }
        }
        vector<pair<int,int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()){
            int i=q.front().second.first;
            int j=q.front().second.second;
            int cost=q.front().first;
            q.pop();
            sol=max(sol,cost);
            for(auto a: dirs){
                int x=i+a.first;
                int y=j+a.second;
                if(x>=0&&x<grid.size()&&y>=0&&y<grid[0].size()&&vis[x][y]==0){
                    if(grid[x][y]==1){init--;grid[x][y]=2;q.push({cost+1,{x,y}});}
                }
            }
        }
        if(init==0){return sol;}
        else{return -1;}
    }
};