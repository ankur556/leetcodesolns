class Solution {
public:
    void helper(vector<vector<int>>& sol, vector<pair<int, bool>>& a, vector<int>& curr) {
        if (curr.size() == a.size()) {
            sol.push_back(curr);
            return;
        }

        for (int i = 0; i < a.size(); i++) {
            if (a[i].second) continue;
            if (i > 0 && a[i].first == a[i-1].first && !a[i-1].second) continue;

            a[i].second = true;
            curr.push_back(a[i].first);
            
            helper(sol, a, curr);
            
            a[i].second = false;
            curr.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<pair<int, bool>> a;
        for (int x : nums) {
            a.push_back({x, false});
        }

        vector<vector<int>> sol;
        vector<int> curr;
        helper(sol, a, curr);
        return sol;
    }
};
