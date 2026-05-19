#include <unordered_map>
#include <algorithm>

class Solution {
    std::unordered_map<long long, int> memo;

public:
    int integerReplacement(int n) {
        return solve(n);
    }

private:
    int solve(long long n) {
        // Base case
        if (n == 1) return 0;
        
        // Return precalculated result if it exists
        if (memo.count(n)) return memo[n];
        
        // If n is even, divide by 2
        if (n % 2 == 0) {
            memo[n] = 1 + solve(n / 2);
        } 
        // If n is odd, take the minimum of n + 1 and n - 1
        else {
            memo[n] = 1 + std::min(solve(n + 1), solve(n - 1));
        }
        
        return memo[n];
    }
};
