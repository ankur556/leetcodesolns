#include <string>

class Solution {
public:
    bool hasSameDigits(string s) {
        
        for (int n = s.size(); n > 2; n--) {
            
            for (int j = 0; j < n - 1; j++) {
                
                int d1 = s[j] - '0';
                int d2 = s[j+1] - '0';
                
                int new_digit = (d1 + d2) % 10;
                
                s[j] = new_digit + '0';
            }
        }
        
        return (s[0] == s[1]);
    }
};
