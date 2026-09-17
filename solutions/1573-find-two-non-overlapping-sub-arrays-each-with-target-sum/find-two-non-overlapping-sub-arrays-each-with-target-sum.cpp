class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        // dp[i] stores the minimum length of a valid subarray ending at or before index i
        vector<int> dp(n, INT_MAX);
        unordered_map<int, int> prefix_sum_map; // prefix_sum -> ending index
        
        int sum = 0;
        int min_len = INT_MAX;
        int ans = INT_MAX;
        
        prefix_sum_map[0] = -1; // Base case for prefix sum
        
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
            
            // Check if there is a prefix sum that gives us `target`
            if (prefix_sum_map.count(sum - target)) {
                int start = prefix_sum_map[sum - target] + 1;
                int len = i - start + 1;
                
                // If there is a valid non-overlapping subarray before `start`
                if (start > 0 && dp[start - 1] != INT_MAX) {
                    ans = min(ans, len + dp[start - 1]);
                }
                
                // Update min_len ending at or before current index
                min_len = min(min_len, len);
            }
            
            dp[i] = min_len;
            prefix_sum_map[sum] = i;
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};