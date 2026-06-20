class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        int torqavemi = n; 
        
        vector<vector<int>> adj(n);
        vector<vector<int>> par(n);
        
        vector<pair<long long, long long>> lh(n, {LLONG_MAX, -LLONG_MAX});
        
        vector<long long> finish(n, 0);
        vector<int> pendingChildren(n, 0); 
        
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            par[edges[i][1]].push_back(edges[i][0]);
            pendingChildren[edges[i][0]]++;
        }
        queue<int> q;
        q.push(0);
        queue<int> helper;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            if(adj[curr].empty()){
                finish[curr] = baseTime[curr];
                helper.push(curr);
            } else {
                for(int child : adj[curr]){
                    q.push(child);
                }
            }
        }
        while(!helper.empty()){
            int curr = helper.front();
            helper.pop();
            if(curr == 0) continue;
            int p = par[curr][0]; 
            lh[p].first = min(lh[p].first, finish[curr]);
            lh[p].second = max(lh[p].second, finish[curr]);pendingChildren[p]--;
            if(pendingChildren[p] == 0){
                finish[p] = lh[p].second + (lh[p].second - lh[p].first) + baseTime[p];
                helper.push(p); 
            }
        }
        
        return finish[0];
    }
};
