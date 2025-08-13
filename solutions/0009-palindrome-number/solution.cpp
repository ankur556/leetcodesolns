class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        if (x % 10 == 0) return false;

        string s;
        int temp = x;
        while (temp > 0) {
            s.push_back((temp % 10) + '0');
            temp /= 10;
        }
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - 1 - i]) return false;
        }
        return true;
    }
};

