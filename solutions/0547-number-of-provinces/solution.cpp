class Solution {
public:
    void bfs(int i,vector<bool>&visited,vector<vector<int>>& adj){
        if(visited[i]){return;}
        visited[i]=true;
        for(int j=0;j<adj[i].size();j++){
            if(adj[i][j]==1){bfs(j,visited,adj);}
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> a(isConnected.size(),-1);
        int n=isConnected.size();
        int count=0;
        vector<bool>visited(isConnected.size());
        for(int i=0;i<n;i++){
            if(!visited[i]){bfs(i,visited,isConnected);count++;}
        }
        return count;
    }
};
