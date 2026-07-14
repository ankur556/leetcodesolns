class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int MOD = 1e9 + 7;
        
        // dp[g1][g2] stores the number of valid disjoint subsequence pairs 
        // with gcd1 == g1 and gcd2 == g2
        // Max value is 200, so we use size 201. 0 represents an empty subsequence.
        vector<vector<int>> dp(201, vector<int>(201, 0));
        
        // Base case: 1 way to have both subsequences empty
        dp[0][0] = 1;
        
        for (int x : nums) {
            vector<vector<int>> next_dp = dp; // Start with the "Skip it" option
            
            for (int g1 = 0; g1 <= 200; g1++) {
                for (int g2 = 0; g2 <= 200; g2++) {
                    if (dp[g1][g2] == 0) continue;
                    
                    // Option 2: Add x to seq1
                    int new_g1 = std::gcd(g1, x);
                    next_dp[new_g1][g2] = (next_dp[new_g1][g2] + dp[g1][g2]) % MOD;
                    
                    // Option 3: Add x to seq2
                    int new_g2 = std::gcd(g2, x);
                    next_dp[g1][new_g2] = (next_dp[g1][new_g2] + dp[g1][g2]) % MOD;
                }
            }
            dp = next_dp;
        }
        
        // Sum up all cases where g1 == g2 and they are greater than 0
        int ans = 0;
        for (int i = 1; i <= 200; i++) {
            ans = (ans + dp[i][i]) % MOD;
        }
        
        return ans;
    }
};