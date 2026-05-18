#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0; // Already at the end

        // Step 1: Build a map to instantly find all indices with the same value
        unordered_map<int, vector<int>> teleport;
        for (int i = 0; i < n; i++) {
            teleport[arr[i]].push_back(i);
        }

        vector<bool> visited(n, false);
        visited[0] = true;
        
        queue<int> q;
        q.push(0);
        int jumps = 0;

        // Step 2: Standard BFS
        while (!q.empty()) {
            int size = q.size();
            
            // Process everything at the current jump level
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();

                // If we reached the end, return the current jump count
                if (curr == n - 1) return jumps;

                // Move 1: Teleport to indices with the same value
                for (int next : teleport[arr[curr]]) {
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
                
                // CRITICAL OPTIMIZATION: Clear the list!
                // Once we've evaluated this value, we never need to check its 
                // teleport list again. If we don't clear it, a massive array of 
                // the same number (e.g., [7,7,7,7...]) will cause O(N^2) time.
                teleport[arr[curr]].clear();

                // Move 2: Step forward
                if (curr + 1 < n && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }
                
                // Move 3: Step backward
                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }
            }
            // Finished a level, increment jumps
            jumps++;
        }
        
        return -1;
    }
};
