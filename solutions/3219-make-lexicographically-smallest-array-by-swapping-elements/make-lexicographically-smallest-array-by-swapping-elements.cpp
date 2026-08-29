#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // 1. Store value and original index pairs
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = {nums[i], i};
        }
        
        // 2. Sort pairs by value
        sort(pairs.begin(), pairs.end());
        
        // 3. Divide sorted elements into connected components (groups)
        vector<vector<pair<int, int>>> groups;
        groups.push_back({pairs[0]});
        
        for (int i = 1; i < n; ++i) {
            // Adjacent elements in sorted order with diff <= limit belong to the same group
            if (pairs[i].first - pairs[i - 1].first <= limit) {
                groups.back().push_back(pairs[i]);
            } else {
                groups.push_back({pairs[i]});
            }
        }
        
        // 4. For each group, assign sorted values to sorted indices
        for (const auto& group : groups) {
            vector<int> indices;
            for (const auto& p : group) {
                indices.push_back(p.second);
            }
            sort(indices.begin(), indices.end());
            
            for (size_t i = 0; i < group.size(); ++i) {
                nums[indices[i]] = group[i].first;
            }
        }
        
        return nums;
    }
};