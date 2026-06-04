class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        int MOD = 1e9 + 7;
        int max_inv = 400; 
        
        vector<int> req(n, -1);
        for (const auto& r : requirements) {
            req[r[0]] = r[1];
        }
        
        if (req[0] > 0) return 0;
        
        vector<vector<long long>> dp(n + 1, vector<long long>(max_inv + 1, 0));
        
        dp[1][0] = 1;
        
        for (int len = 2; len <= n; len++) {
            for (int c = 0; c <= max_inv; c++) {
                for (int k = 0; k < len && c - k >= 0; k++) {
                    dp[len][c] = (dp[len][c] + dp[len - 1][c - k]) % MOD;
                }
            }
            
            if (req[len - 1] != -1) {
                int required_c = req[len - 1];
                for (int c = 0; c <= max_inv; c++) {
                    if (c != required_c) {
                        dp[len][c] = 0; 
                    }
                }
            }
        }
        
        return dp[n][req[n - 1]];
    }
};
