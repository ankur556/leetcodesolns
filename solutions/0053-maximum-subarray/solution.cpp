class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum1 = 0, sum2 = 0, sum3 = INT_MIN;
        int left = 0, right = n - 1;
        int max_forward = INT_MIN;
        sum1 = 0;
        for (int i = 0; i < n; i++) {
            sum1 += nums[i];
            if (sum1 > max_forward) max_forward = sum1;
            if (sum1 < 0) sum1 = 0;
        }
        int max_backward = INT_MIN;
        sum2 = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum2 += nums[i];
            if (sum2 > max_backward) max_backward = sum2;
            if (sum2 < 0) sum2 = 0;
        }
        sum3 = max(max_forward, max_backward);
        return sum3;
    }
};

