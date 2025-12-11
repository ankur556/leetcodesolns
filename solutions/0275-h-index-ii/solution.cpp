class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        int low = 0;
        int high = n; // High starts at n, not n-1, to handle [0] case correctly

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (c[mid] >= n - mid) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return n - low;
    }
};
