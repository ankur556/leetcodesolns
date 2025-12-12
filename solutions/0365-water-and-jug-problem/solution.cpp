#include <numeric> // Required for std::gcd

class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        // Case 1: Target is greater than total capacity
        if (target > x + y) {
            return false;
        }
        
        // Case 2: If the target is exactly the sum (optimization)
        if (target == x + y) {
            return true;
        }
        
        // Case 3: Handle potential division by zero
        // If x=0 and y=0, gcd is 0. 
        if (x == 0 && y == 0) {
            return target == 0;
        }
        
        // Case 4: Bézout's Identity
        // Check if target is a multiple of GCD(x, y)
        return target % std::gcd(x, y) == 0;
    }
};
