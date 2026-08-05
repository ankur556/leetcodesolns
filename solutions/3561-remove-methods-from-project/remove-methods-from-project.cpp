class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<vector<int>> biadj(n);
        for (int i = 0; i < invocations.size(); i++) {
            adj[invocations[i][0]].push_back(invocations[i][1]);
            biadj[invocations[i][0]].push_back(invocations[i][1]);
            biadj[invocations[i][1]].push_back(invocations[i][0]);
        }
        bool h = false;
        vector<int> vis(n);
        queue<int> q;
        q.push(k);
        vis[k] = 1;
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            for (int i : biadj[f]) {
                if (vis[i] == 0) {
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
        vector<int> vis2(n);
        vis2[k] = 1;
        q.push(k);
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            for (int i : adj[f]) {
                if (vis2[i] == 0) {
                    q.push(i);
                    vis2[i] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (vis[i] == 1 && vis2[i] == 0) {
                h = true;
            }
        }
        if (h) {
            vector<int> sol;
            for (int i = 0; i < n; i++) {
                sol.push_back(i);
            }
            return sol;
        }
        vector<int> help;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                help.push_back(i);
            }
        }
        return help;
    }
};