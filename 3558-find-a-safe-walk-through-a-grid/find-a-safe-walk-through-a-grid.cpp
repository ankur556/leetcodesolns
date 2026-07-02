class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        q.push({grid[0][0],{0,0}});
        vector<vector<int>> vis (grid.size(),vector<int>(grid[0].size()));
        vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            int a1=q.top().second.first;
            int a2=q.top().second.second;
            int val=q.top().first;
            q.pop();
            if(vis[a1][a2]==1){
            }
            else{
                vis[a1][a2]=1;
                for(auto a: dirs){
                    int t1=a1+a.first;
                    int t2=a2+a.second;
                    if(t1>=0&&t1<grid.size()&&t2>=0&&t2<grid[0].size()){
                        if(t1==grid.size()-1&&t2==grid[0].size()-1){return (health>(grid[t1][t2]+val));}
                        else{q.push({val+grid[t1][t2],{t1,t2}});}
                    }
                }
            }
        }
        return false;
    }
};