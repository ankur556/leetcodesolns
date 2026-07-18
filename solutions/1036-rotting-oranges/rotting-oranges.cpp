class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int st=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){q.push({0,{i,j}});}
                else if(grid[i][j]==1){st++;}
            }
        }
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size()));
        vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
        int sol=0;
        //int cnt=0;
        while(!q.empty()){
            int val=q.front().first;
            int i1=q.front().second.first;
            int i2=q.front().second.second;
            q.pop();
            if(val>sol){sol=val;}
            vis[i1][i2]=1;
            for(auto a: dirs){
                int a1=i1+a.first;
                int a2=i2+a.second;
                if(a1>=0&&a1<grid.size()&&a2>=0&&a2<grid[0].size()){
                    if(vis[a1][a2]==0&&grid[a1][a2]==1){
                        grid[a1][a2]=2;
                        vis[a1][a2]=1;
                        q.push({val+1,{a1,a2}});
                        st--;
                    }
                }
            }
        }
        if(st==0)return sol;
        return -1;
    }
};