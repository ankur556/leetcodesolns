class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Number of passes needed; loosely using n for bubble-like sorting
        for (int k = 0; k < n; k++) {
            // Iterate over elements except last row and column
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - 1; j++) {
                    // Identify which triangle the diagonal element belongs to
                    if (i >= j) { // bottom-left triangle including main diagonal
                        if (grid[i][j] < grid[i + 1][j + 1]) {
                            swap(grid[i][j], grid[i + 1][j + 1]); // non-increasing order
                        }
                    } else { // top-right triangle
                        if (grid[i][j] > grid[i + 1][j + 1]) {
                            swap(grid[i][j], grid[i + 1][j + 1]); // non-decreasing order
                        }
                    }
                }
            }
        }

        return grid;
    }
};

