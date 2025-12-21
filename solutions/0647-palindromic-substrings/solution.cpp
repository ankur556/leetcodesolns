class Solution {
public:
    bool ispanildrome(string& a, int low, int high) {
        // Standard two-pointer check is safer and cleaner
        while(low < high) {
            if(a[low] != a[high]) {
                return false; 
            }
            low++;
            high--;
        }
        return true;
    }

    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) { // Fixed loop condition
                if(ispanildrome(s, i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
