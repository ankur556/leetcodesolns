#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int bs(int idx, const vector<vector<int>>& intervals) {
        int target_end = intervals[idx][1];
        int left = 0;
        int right = intervals.size() - 1;
        int ans = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (intervals[mid][0] >= target_end) {
                ans = intervals[mid][2];
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        for(int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }
        
        sort(intervals.begin(), intervals.end());
        
        vector<int> sol(n);
        
        for(int i = 0; i < n; i++){
            sol[intervals[i][2]] = bs(i, intervals);
        }
        
        return sol;
    }
};
