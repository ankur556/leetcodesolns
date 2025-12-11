#include <vector>
#include <algorithm>
#include <climits> // For INT_MAX

using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // Initialize Minimums to a large value and Maximums to a small value
        vector<int> min_y_in_row(n + 1, INT_MAX);
        vector<int> max_y_in_row(n + 1, -1);
        vector<int> min_x_in_col(n + 1, INT_MAX);
        vector<int> max_x_in_col(n + 1, -1);

        // PASS 1: Find the boundaries
        for (const auto& b : buildings) {
            int r = b[0]; // Row coordinate (x)
            int c = b[1]; // Col coordinate (y)

            // For this row (r), update min/max column (y)
            if (c < min_y_in_row[r]) min_y_in_row[r] = c;
            if (c > max_y_in_row[r]) max_y_in_row[r] = c;

            // For this col (c), update min/max row (x)
            if (r < min_x_in_col[c]) min_x_in_col[c] = r;
            if (r > max_x_in_col[c]) max_x_in_col[c] = r;
        }

        int ans = 0;

        // PASS 2: Check if covered
        for (const auto& b : buildings) {
            int r = b[0];
            int c = b[1];

            // Check Horizontal (Left and Right exist)
            // Left exists if min_y_in_row[r] is smaller than current c
            // Right exists if max_y_in_row[r] is larger than current c
            bool has_horizontal = (min_y_in_row[r] < c && max_y_in_row[r] > c);

            // Check Vertical (Above and Below exist)
            // Above/Below exist if min_x_in_col[c] < r < max_x_in_col[c]
            bool has_vertical = (min_x_in_col[c] < r && max_x_in_col[c] > r);

            if (has_horizontal && has_vertical) {
                ans++;
            }
        }

        return ans;
    }
};
