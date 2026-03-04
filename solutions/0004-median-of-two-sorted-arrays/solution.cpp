class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();
        int left = 0, right = n1;

        while (left <= right) {
            int cut1 = (left + right) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            // Edge cases: if cut is at the very beginning or end
            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1) {
                // Correct partition found
                if ((n1 + n2) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return max(l1, l2);
                }
            } else if (l1 > r2) {
                // Move left in nums1
                right = cut1 - 1;
            } else {
                // Move right in nums1
                left = cut1 + 1;
            }
        }
        return 0.0;
    }
};
