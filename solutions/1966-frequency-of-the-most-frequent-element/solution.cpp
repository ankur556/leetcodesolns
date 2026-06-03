class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // 1. Sort the array so we are only incrementing smaller numbers up
        sort(nums.begin(), nums.end());
        
        int left = 0;
        int max_freq = 0;
        long long cur_sum = 0; // Use long long to prevent overflow
        
        // 2. Expand the window to the right
        for (int right = 0; right < nums.size(); right++) {
            cur_sum += nums[right];
            
            // 3. The Math Check: Cost = (Size * Target) - Sum
            // If the cost is strictly greater than k, our window is too big!
            while ((long long)(right - left + 1) * nums[right] - cur_sum > k) {
                cur_sum -= nums[left]; // Remove the leftmost element from sum
                left++;                // Shrink the window from the left
            }
            
            // 4. Record the max valid window size we've seen
            if (right - left + 1 > max_freq) {
                max_freq = right - left + 1;
            }
        }
        
        return max_freq;
    }
};
