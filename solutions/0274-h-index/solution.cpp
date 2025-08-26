class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 0) return 0;

        int maxCitation = *max_element(citations.begin(), citations.end());
        int limit = max(n, maxCitation);
        int ans = 0;

        // Count how many papers have at least i citations efficiently using sorting
        sort(citations.begin(), citations.end());

        for (int h = 0; h <= limit; h++) {
            // Use binary search to find how many papers have citations >= h
            auto it = lower_bound(citations.begin(), citations.end(), h);
            int count = citations.end() - it;

            if (count >= h) {
                ans = h;  // update h-index
            }
        }
        return ans;
    }
};

