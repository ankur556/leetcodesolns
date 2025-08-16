class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        int n = haystack.size();
        int m = needle.size();

        // Only check starting positions where needle can fit
        for (int i = 0; i <= n - m; i++) {
            if (haystack[i] == needle[0]) {
                int sim = 0;
                for (int j = 0; j < m; j++) {
                    if (haystack[i + j] == needle[j]) {
                        sim++;
                    } else {
                        break;
                    }
                }
                if (sim == m) return i;
            }
        }
        return -1;
    }
};

