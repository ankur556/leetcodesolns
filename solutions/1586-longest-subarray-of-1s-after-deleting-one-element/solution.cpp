
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int total_zeros = 0;
        for (int n : nums) {
            if (n == 0) {
                total_zeros++;
            }
        }

        if (total_zeros == 0 || total_zeros == 1) {
            return nums.size() - 1;
        }

        int max_len = 0;
        int left_count = 0;
        int right_count = 0;

        for (int n : nums) {
            if (n == 1) {
                right_count++;
            } else {
                max_len = max(max_len, left_count + right_count);
                left_count = right_count;
                right_count = 0;
            }
        }
        
        max_len = max(max_len, left_count + right_count);

        return max_len;
    }
};

