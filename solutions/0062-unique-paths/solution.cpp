class Solution {
public:
    int uniquePaths(int m, int n) {
        // Calculate C(m+n-2, n-1) or C(m+n-2, m-1)
        int N = m + n - 2;
        int k = min(m - 1, n - 1);  // choose smaller to reduce iterations
        unsigned long long result = 1;

        for (int i = 1; i <= k; ++i) {
            result = result * (N - k + i) / i;
        }

        return (int)result;
    }
};

