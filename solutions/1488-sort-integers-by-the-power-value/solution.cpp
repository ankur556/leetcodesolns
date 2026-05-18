#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    // DP cache to store the power of numbers we've already calculated
    unordered_map<int, int> memo;
    
    int getPower(int x) {
        // Base case: it takes 0 steps to reach 1 from 1
        if (x == 1) return 0;
        
        // If we already calculated this, return the saved answer
        if (memo.count(x)) return memo[x];
        
        // Collatz rules
        if (x % 2 == 0) {
            return memo[x] = 1 + getPower(x / 2);
        } else {
            return memo[x] = 1 + getPower(3 * x + 1);
        }
    }
    
public:
    int getKth(int lo, int hi, int k) {
        // Store pairs of {power_value, actual_number}
        vector<pair<int, int>> powers;
        
        for (int i = lo; i <= hi; i++) {
            powers.push_back({getPower(i), i});
        }
        
        // Sort automatically handles:
        // 1. Ascending by power (first element)
        // 2. Ascending by value (second element) if powers are equal
        sort(powers.begin(), powers.end());
        
        // k is 1-indexed, but vectors are 0-indexed, so we want k - 1
        return powers[k - 1].second;
    }
};
