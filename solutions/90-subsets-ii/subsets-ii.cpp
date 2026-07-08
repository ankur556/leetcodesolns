class Solution {
public:
    void backtrack(vector<vector<int>>& sol, vector<int>& current, vector<int>& nums, int start) {
        sol.push_back(current);
        
        for (int i = start; i < nums.size(); ++i) {
            // Skip duplicates: if the current number is the same as the previous one, skip it
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            
            current.push_back(nums[i]);
            backtrack(sol, current, nums, i + 1);
            current.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> current;
        
        // 1. Sort the input array to handle duplicates easily
        sort(nums.begin(), nums.end()); 
        
        // 2. Start backtracking
        backtrack(sol, current, nums, 0);
        
        return sol;
    }
};