class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
       vector<vector<int>> adj(n);
       vector<int> deg(n);
       for(int i=0;i<n;i++){
        for(int j=0;j<graph[i].size();j++){
            adj[graph[i][j]].push_back(i);deg[i]++;
        }
       }
       queue<int> q;
       vector<int> vis(n);
       for(int i=0;i<n;i++){if(deg[i]==0){q.push(i);}}
       vector<int> sol;
       while(!q.empty()){
        int a=q.front();
        q.pop();
        if(vis[a]==0){
            //sol.push_back(a);
            vis[a]=1;
            for(int k:adj[a]){
                deg[k]--;
                if(deg[k]==0){q.push(k);}
            }
        }
        else{}
    }
    for(int i=0;i<n;i++){if(deg[i]<=0){sol.push_back(i);}}
    return sol;
    }
};