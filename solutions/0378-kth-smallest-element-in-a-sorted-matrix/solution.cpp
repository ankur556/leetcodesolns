#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        // Min-heap to store {value, row_index, col_index}
        // "greater" makes it a min-heap (smallest at top)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        // 1. Initialize: Push the first element of every row
        // We assume the matrix is N x N. 
        // We use min(n, k) because if k < n, we don't need to look at row k+1.
        for(int r = 0; r < min(n, k); r++) {
            pq.push({matrix[r][0], r, 0});
        }
        
        int ans = -1;
        
        // 2. Extract min k times
        for(int i = 0; i < k; i++) {
            // Get the smallest element currently in the heap
            vector<int> top = pq.top();
            pq.pop();
            
            ans = top[0]; // The value
            int r = top[1]; // The row it came from
            int c = top[2]; // The col it came from
            
            // 3. If there is a next element in this specific row, push it
            if(c + 1 < n) {
                pq.push({matrix[r][c + 1], r, c + 1});
            }
        }
        
        return ans;
    }
};
