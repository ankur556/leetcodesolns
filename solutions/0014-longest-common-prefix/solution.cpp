class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        int minLength = strs[0].size();
        for (const string& s : strs) {
            minLength = min(minLength, (int)s.size());
        }

        int ans = 0;
        for (int i = 0; i < minLength; i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != c) {
                    return strs[0].substr(0, ans);
                }
            }
            ans++;
        }

        return strs[0].substr(0, ans);
    }
};

