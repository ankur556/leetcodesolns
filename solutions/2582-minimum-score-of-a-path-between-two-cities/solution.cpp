class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto a: roads){
            adj[a[0]].push_back({a[2],a[1]}); adj[a[1]].push_back({a[2],a[0]});
        }
        queue<int> q;
        q.push(1);
        int sol=1e9;
        vector<int> vis(n+1,0);
        while(!q.empty()){
            int a=q.front();
            q.pop();
            if(vis[a]==1){}
            else{
                vis[a]=1;
                for(auto n: adj[a]){
                    if(n.first<sol){sol=n.first;}
                    q.push(n.second);
                }
            }
        }
        return sol;
    }
};
