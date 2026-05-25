class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int nr=0;
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){q.push({i,j});}
                if(grid[i][j]==1){nr++;}
            }
        }
        int sol=0;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()&&nr>0){
            pair<int,int> a=q.front();
            q.pop();
            for(auto dir:dirs){
                int r=a.first;
                int c=a.second;
                int ra=a.first+dir.first;
                int rc=a.second+dir.second;
                if(ra>=0&&ra<grid.size()&&rc>=0&&rc<grid[0].size()){
                    if(grid[ra][rc]==1){grid[ra][rc]=grid[r][c]+1;nr--;q.push({ra,rc});if(grid[ra][rc]>sol){sol=grid[ra][rc];}}
                }
            }
        }
        if(nr>0){return -1;}
        else{
            if(sol<2){return 0;}
            return sol-2;}
    }
};
