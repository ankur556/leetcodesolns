class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size()));
        for(int i=0;i<grid.size();i++){if(grid[i][0]==1){q.push({i,0});grid[i][0]=2;}}
        for(int i=0;i<grid.size();i++){if(grid[i][grid[0].size()-1]==1){q.push({i,grid[0].size()-1});grid[i][grid[0].size()-1]=2;}}
        for(int i=0;i<grid[0].size();i++){if(grid[0][i]==1){q.push({0,i});grid[0][i]=2;}}
        for(int i=0;i<grid[0].size();i++){if(grid[grid.size()-1][i]==1){q.push({grid.size()-1,i});grid[grid.size()-1][i]=2;}}
        int x[4]={1,0,-1,0};
        int y[4]={0,1,0,-1};
        while(!q.empty()){
            int x1=q.front().first;
            int y1=q.front().second;
            q.pop();
            if(visited[x1][y1]==1){}
            else{
                visited[x1][y1]=1;
                for(int i=0;i<4;i++){
                    int x2=x1+x[i];
                    int y2=y1+y[i];
                    if(x2>=0&&x2<grid.size()&&y2>=0&&y2<grid[0].size()){
                        if(grid[x2][y2]==1){q.push({x2,y2});grid[x2][y2]=2;}
                    }
                }

            }
        }
        int sol=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){sol++;}
            }
        }
        return sol;
    }
};
