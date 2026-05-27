class Solution {
public:
    const long long MOD = 1000000007;
    
    // Helper function for Binary Exponentiation
    long long power(long long base, long long exp) {
        long long result = 1;
        base = base % MOD;
        
        while (exp > 0) {
            // If exp is odd, multiply the base with the result
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            // Square the base and halve the exponent
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }
    
    int countGoodNumbers(long long n) {
        long long even_positions = n / 2 + n % 2; // Ceil of n/2
        long long odd_positions = n / 2;          // Floor of n/2
        
        long long first_part = power(5, even_positions);
        long long second_part = power(4, odd_positions);
        
        // Multiply and take modulo one last time
        return (first_part * second_part) % MOD;
    }
};
