class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int tot = 0;
        bool hasNonZero = false;

        for (int x : nums) {
            tot ^= x;
            if (x != 0) hasNonZero = true;
        }

        if (tot != 0) return nums.size();
        if (hasNonZero) return nums.size() - 1;
        return 0;
    }
};