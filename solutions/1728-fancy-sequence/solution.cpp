#include <vector>

using namespace std;

class Fancy {
public:
    vector<long long> a;
    long long multi;
    long long add;
    const int mod = 1e9 + 7;

    Fancy() {
        multi = 1;
        add = 0;
    }

    // Helper function for fast exponentiation (x^y % mod)
    long long power(long long x, long long y) {
        long long res = 1;
        x = x % mod;
        while (y > 0) {
            // If y is odd, multiply x with the result
            if (y & 1) {
                res = (res * x) % mod;
            }
            // y must be even now
            y = y >> 1; // Divide y by 2
            x = (x * x) % mod;
        }
        return res;
    }

    // Helper function to find modular inverse
    long long modInverse(long long n) {
        return power(n, mod - 2);
    }

    void append(int val) {
        // Reverse engineer the value to store: (val - add) / multi
        long long adjusted_val = (val - add + mod) % mod; // +mod ensures no negative numbers
        adjusted_val = (adjusted_val * modInverse(multi)) % mod;
        a.push_back(adjusted_val);
    }

    void addAll(int inc) {
        add = (add + inc) % mod;
    }

    void multAll(int m) {
        multi = (multi * m) % mod;
        add = (add * m) % mod;
    }

    int getIndex(int idx) {
        if (idx >= a.size()) {
            return -1;
        }
        // Apply the global multi and add to the stored value
        long long result = (a[idx] * multi) % mod;
        result = (result + add) % mod;
        return result;
    }
};
