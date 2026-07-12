class Solution {
public:
    // Helper 1: Checks if words differ by exactly one character
    bool isval(const string& a, const string& b) {
        int diff = 0;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] != b[i]) {
                if (++diff > 1) return false;
            }
        }
        return diff == 1;
    }

    // Helper 2: DFS to backtrack from endWord to beginWord and build paths
    void dfs(int current, int target, const vector<vector<int>>& parents, 
             const vector<string>& wordList, vector<string>& path, 
             vector<vector<string>>& results) {
        
        // Add current word to the path
        path.push_back(wordList[current]);
        
        if (current == target) {
            // We reached the beginWord, reverse the path and add to results
            vector<string> validPath = path;
            reverse(validPath.begin(), validPath.end());
            results.push_back(validPath);
        } else {
            // Traverse backward through the parent nodes
            for (int parent : parents[current]) {
                dfs(parent, target, parents, wordList, path, results);
            }
        }
        
        // Backtrack
        path.pop_back(); 
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // 1. Check if endWord even exists in the list
        auto it = find(wordList.begin(), wordList.end(), endWord);
        if (it == wordList.end()) return {}; 
        int endIndex = distance(wordList.begin(), it);

        // 2. Add beginWord to the list to make graph indexing easier
        wordList.push_back(beginWord);
        int beginIndex = wordList.size() - 1;
        int n = wordList.size();

        // 3. Build Adjacency List (Your O(N^2) logic, corrected)
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isval(wordList[i], wordList[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // 4. BFS to find shortest paths and build parent pointers
        vector<vector<int>> parents(n);
        vector<int> dist(n, -1);
        queue<int> q;

        q.push(beginIndex);
        dist[beginIndex] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    // First time visiting this node
                    dist[v] = dist[u] + 1;
                    parents[v].push_back(u);
                    q.push(v);
                } else if (dist[v] == dist[u] + 1) {
                    // Re-visiting node via another shortest path
                    parents[v].push_back(u);
                }
            }
        }

        // 5. Trigger DFS to format the results
        vector<vector<string>> results;
        vector<string> path;
        if (dist[endIndex] != -1) {
            dfs(endIndex, beginIndex, parents, wordList, path, results);
        }
        
        return results;
    }
};