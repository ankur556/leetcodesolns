class Solution {
public:
    bool is_val(string& s, int st, int end) {
        // Check bounds and ensure it's exactly a 2-character window
        if (st < 0 || end >= s.size() || end != st + 1) {
            return false;
        }
        
        // A valid 2-digit decoding cannot start with '0'
        if (s[st] == '0') {
            return false;
        }
        
        // Calculate the integer correctly: (first_digit * 10) + second_digit
        int k = (s[st] - '0') * 10 + (s[end] - '0');
        
        // The number must be between 1 and 26
        return k >= 1 && k <= 26;
    }

    int numDecodings(string s) {
        // Base case: if the string is empty or starts with '0', it's invalid
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        
        // Use an array of size n+1 to handle looking back 2 spaces safely
        vector<int> dp(s.size() + 1, 0);
        
        dp[0] = 1; // 1 way to decode an empty prefix
        dp[1] = 1; // 1 way to decode the first valid character
        
        // Start checking from the second character in the string (dp index 2)
        for (int i = 2; i <= s.size(); i++) {
            
            // 1. Single character decode: Only valid if the current char is NOT '0'
            // Note: s[i-1] matches the current character for dp[i]
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1]; 
            }
            
            // 2. Double character decode: Use your helper function
            // Check the previous character s[i-2] and current character s[i-1]
            if (is_val(s, i - 2, i - 1)) {
                dp[i] += dp[i - 2];
            }
        }
        
        // The final answer is at the very end of our padded DP array
        return dp[s.size()];
    }
};
