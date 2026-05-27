class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        vector<vector<int>>visited=image;
        for(int i=0;i<visited.size();i++){
            for(int j=0;j<visited[0].size();j++){
                visited[i][j]=0;
            }
        }
        //cout<<visited.size()<<" "<<visited[0].size()<<endl;
        q.push({sr,sc});
        vector<pair<int,int>>dirs;
        int og=image[sr][sc];image[sr][sc]=color;
        dirs.push_back({1,0});
        dirs.push_back({0,1});
        dirs.push_back({-1,0});
        dirs.push_back({0,-1});
        while(!q.empty()){
            pair<int,int> a=q.front();
            q.pop();
            if(visited[a.first][a.second]==1){}
            else{visited[a.first][a.second]=1;
            for(auto dir:dirs){
                int r=a.first;
                int c=a.second;
                int nr=r+dir.first;
                int nc=c+dir.second;
                if(nr>=0&&nr<image.size()&&nc>=0&&nc<image[0].size()){
                    if(image[nr][nc]==og&&visited[nr][nc]==0){image[nr][nc]=color;q.push({nr,nc});}
                }
                }
            }
        }
        return image;
    }
};
