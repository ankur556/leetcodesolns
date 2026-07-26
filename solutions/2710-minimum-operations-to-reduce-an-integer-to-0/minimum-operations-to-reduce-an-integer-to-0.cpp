class Solution {
public:
    int minOperations(int n) {
        int ops = 0;
        while (n > 0) {
            // If the last two bits end in '11' (i.e., multiple consecutive ones)
            if ((n & 3) == 3) {
                n += 1;
                ops++;
            } 
            // If the last bit is 1 and the second to last is 0 (i.e., a single isolated 1)
            else if ((n & 3) == 1) {
                n -= 1;
                ops++;
            } 
            // If the last bit is 0, just shift right
            else {
                n >>= 1;
            }
        }
        return ops;
    }
};