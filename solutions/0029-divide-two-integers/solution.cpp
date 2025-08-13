#include <climits>
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Special overflow case
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // Work with absolute values in long long to avoid overflow
        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);
        long long result = 0;

        // Fast division using bit shifts (O(log n))
        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            // Double temp until it would exceed 'a'
            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            result += multiple;
        }

        // Determine sign
        bool negative = (dividend < 0) ^ (divisor < 0);
        if (negative) result = -result;

        return (int)result;
    }
};

