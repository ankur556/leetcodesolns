class Solution {
public:
    long long countCommas(long long n) {
        long long commas = 0;
        for (long long base = 1000; base <= n; base *= 1000) {
            commas += (n - base + 1);
        }
        return commas;
    }
};