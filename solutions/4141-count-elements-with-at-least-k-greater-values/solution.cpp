class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        // Base case: If k is 0, all elements are qualified
        if (k == 0) return nums.size();
        
        sort(nums.begin(), nums.end());
        
        // The k-th largest element (including duplicates) is at index n - k
        int target = nums[nums.size() - k];
        
        // We want the count of elements strictly less than the target. 
        // lower_bound finds the first element >= target, giving us that exact count.
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
