#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // If the start or end is blocked, no path exists
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        // BFS requires a queue
        queue<pair<int, int>> q;
        
        // 8 directions (removed the duplicate {-1, -1} from your original code)
        vector<pair<int, int>> dirs = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}, 
            {1, 1}, {-1, -1}, {-1, 1}, {1, -1}
        };

        // Start BFS
        q.push({0, 0});
        grid[0][0] = 1; // We can use the grid itself to track visited cells AND distance

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            // If we've reached the bottom-right corner, return the distance
            if (r == n - 1 && c == n - 1) {
                return grid[r][c];
            }

            // Explore all valid 8 directions
            for (auto d : dirs) {
                int nr = r + d.first;
                int nc = c + d.second;

                // Check out-of-bounds and if the cell is unvisited (0)
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    q.push({nr, nc});
                    // Mark as visited by updating it to the current path length + 1
                    grid[nr][nc] = grid[r][c] + 1; 
                }
            }
        }
        
        // If the queue empties and we haven't reached the end, there's no valid path
        return -1; 
    }
};
