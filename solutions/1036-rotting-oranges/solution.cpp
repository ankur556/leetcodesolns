class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<pair<int,int>>dirs;
        int left=0;
        vector<vector<int>> visited=grid;
        dirs.push_back({0,1});
        dirs.push_back({1,0});
        dirs.push_back({-1,0});
        dirs.push_back({0,-1});
        int max=2;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                visited[i][j]=0;
                if(grid[i][j]==2){q.push({i,j});}
                else if(grid[i][j]==1){left++;}
            }
        }
       // int max=0;
        while(!q.empty()){
            int f=q.front().first;
            int s=q.front().second;
            q.pop();
            if(visited[f][s]==0){
            visited[f][s]=1;
            for(auto dir:dirs){
                int fc=f+dir.first;
                int sc=s+dir.second;
                if(fc>=0&&fc<grid.size()&&sc>=0&&sc<grid[0].size()){
                    if(grid[fc][sc]==1){grid[fc][sc]=grid[f][s]+1;q.push({fc,sc});left--;}
                    if(grid[fc][sc]>max){max=grid[fc][sc];}
                }
            }
        }
        }
        if(left>0){return -1;}
        else{return max-2;}
    }
};
