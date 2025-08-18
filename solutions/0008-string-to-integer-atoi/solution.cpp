class Solution {
public:
    int myAtoi(string s) {
        long long num = 0;
        int i = 0;
        int n = s.size();
        bool neg = false;
        while (i < n && s[i] == ' ') i++;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') neg = true;
            i++;
        }
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            if (!neg && num > INT_MAX) return INT_MAX;
            if (neg && -num < INT_MIN) return INT_MIN;

            i++;
        }

        return neg ? -num : num;
    }
};

