class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid.size()));
        queue<pair<int,int>> q;
        vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(1==grid[i][j]){grid[i][j]=0;q.push({i,j});}
                else{grid[i][j]=1e7;}
            }
        }
        while(!q.empty()){
            int a1=q.front().first;
            int a2=q.front().second;
            q.pop();
            if(1==vis[a1][a2]){}
            else{
                vis[a1][a2]=1;
                for(auto a:dirs){
                    int q1=a1+a.first;
                    int q2=a2+a.second;
                    if(q1>=0&&q1<grid.size()&&q2>=0&&q2<grid.size()){
                        grid[q1][q2]=min(grid[q1][q2],grid[a1][a2]+1);q.push({q1,q2});
                    }
                }
            }
        }
        priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({grid[0][0],{0,0}});
    while(!pq.empty()){
        int b1=pq.top().second.first;
        int b2=pq.top().second.second;
        pq.pop();
        if(vis[b1][b2]==2){}
        else{
            vis[b1][b2]=2;
            for(auto b: dirs){
                int t1=b1+b.first;
                int t2=b2+b.second;
                if(t1>=0&&t1<grid.size()&&t2>=0&&t2<grid.size()){
                    grid[t1][t2]=min(grid[t1][t2],grid[b1][b2]);
                    pq.push({grid[t1][t2],{t1,t2}});
                    if(t1==grid.size()-1&&t2==grid.size()-1){return grid[t1][t2];}
                }
            }
        }
        }  
        return grid[grid.size()-1][grid.size()-1];
    }
};