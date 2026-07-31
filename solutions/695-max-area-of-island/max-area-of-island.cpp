class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int bfs(vector<vector<int>>& vis, vector<vector<int>>& grid, int x, int y) {
        queue<pair<int, int>> q;
        q.push({x, y});
        int cur = 1;
        vis[x][y] = 1;
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (auto a : dirs) {
                int x1 = i + a.first;
                int y1 = j + a.second;
                if (x1 >= 0 && x1 < grid.size() && y1 >= 0 &&
                    y1 < grid[0].size()) {
                    if (vis[x1][y1] != 1 && grid[x1][y1] == 1) {
                        cur++;
                        vis[x1][y1] = 1;
                        q.push({x1, y1});
                    }
                }
            }
        }
        return cur;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int sol = 0;
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    vis[i][j] = 1;
                    sol = std::max(sol, bfs(vis, grid, i, j));
                }
            }
        }
        // int sol=0;
        return sol;
    }
};