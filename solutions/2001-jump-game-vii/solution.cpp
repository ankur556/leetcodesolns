class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        // Edge case: We can never land on the end if it's a '1'
        if (s.back() == '1') {
            return false;
        }
        
        int n = s.size();
        vector<bool> dp(n, false);
        dp[0] = true;
        
        // This keeps track of how many valid jump locations are in our current window
        int reachableInWindow = 0;
        
        for (int i = 1; i < n; i++) {
            // 1. Add the index that just entered our valid [i - maxJump, i - minJump] window
            if (i >= minJump && dp[i - minJump]) {
                reachableInWindow++;
            }
            
            // 2. Remove the index that just fell behind our valid window
            if (i > maxJump && dp[i - maxJump - 1]) {
                reachableInWindow--;
            }
            
            // 3. If there is at least one valid jump spot in the window, and current is '0'
            if (reachableInWindow > 0 && s[i] == '0') {
                dp[i] = true;
            }
        }
        
        return dp[n - 1];
    }
};
