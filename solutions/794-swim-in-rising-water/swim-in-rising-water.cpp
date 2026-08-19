class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
      priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
      pq.push({grid[0][0],0,0});
      vector<pair<int,int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
      vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),1e5));
      while(!pq.empty()){
        int x=pq.top()[1];
        int y=pq.top()[2];
        int val=pq.top()[0];
        if(x==grid.size()-1&&y==grid[0].size()-1){return val;}
        pq.pop();
        for(auto a : dirs){
            int x1=x+a.first;
            int y1=y+a.second;
            if(x1>=0&&x1<grid.size()&&y1>=0&&y1<grid[0].size()){
                int new_val=std::max(val,grid[x1][y1]);
                if(vis[x1][y1]>new_val){pq.push({new_val,x1,y1});vis[x1][y1]=new_val;}
            }
        }
      } 
      return grid.size()*grid.size();
    }
};