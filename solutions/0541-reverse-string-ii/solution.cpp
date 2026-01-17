class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k) {
            int l = i;
            // The right bound is inclusive here, so we subtract 1. 
            // We check against n-1 to ensure we don't access outside the string.
            int r = min(i + k, n) - 1; 
            
            while (l < r) {
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};
