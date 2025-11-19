class Solution {
public:
    int jump(vector<int>& nums) {
        // Edge case: If array length is 1, we are already at the end.
        if (nums.size() <= 1) return 0;

        int jumps = 0;
        int current_end = 0;
        int farthest = 0;

        // We iterate to nums.size() - 1 because we don't need to jump FROM the last element.
        for (int i = 0; i < nums.size() - 1; i++) {
            // Update the furthest point reachable from the current index i
            farthest = max(farthest, i + nums[i]);

            // If we have reached the end of the current jump range
            if (i == current_end) {
                jumps++;             // We must take a jump
                current_end = farthest; // Update the range for the next jump

                // Optimization: If the new range already covers the last index, break early
                if (current_end >= nums.size() - 1) break;
            }
        }

        return jumps;
    }
};
