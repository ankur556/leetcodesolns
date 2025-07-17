class Solution {
public:
    // Helper: Find the maximal product by removing prefix/suffix around negatives
    int maxNegSubarrayProduct(const std::vector<int>& nums, int l, int r) {
        int res = INT_MIN;

        // Remove prefix up to first negative
        int prod = 1;
        bool foundNeg = false;
        for (int i = l; i < r; ++i) {
            prod *= nums[i];
            if (nums[i] < 0 && !foundNeg) {
                foundNeg = true;
                int suffixProd = 1;
                for (int j = i + 1; j < r; ++j)
                    suffixProd *= nums[j];
                res = std::max(res, suffixProd);
            }
        }
        // Remove suffix after last negative
        foundNeg = false;
        prod = 1;
        for (int i = r - 1; i >= l; --i) {
            prod *= nums[i];
            if (nums[i] < 0 && !foundNeg) {
                foundNeg = true;
                int prefixProd = 1;
                for (int j = l; j < i; ++j)
                    prefixProd *= nums[j];
                res = std::max(res, prefixProd);
            }
        }
        return res;
    }

    int maxProduct(std::vector<int>& nums) {
        int n = nums.size();

        // Edge case: array of size 1
        if (n == 1) return nums[0];

        // Edge case: [-?, 0, -?]
        if (n == 3 && nums[1] == 0 && nums[0] < 0 && nums[2] < 0)
            return std::max({nums[0], nums[2], 0});

        // Edge case: all zeros or only single negatives (all isolated by zeros)
        int cntNeg = 0, cntNZ = 0, cntIsolatedNeg = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < 0) {
                cntNeg++;
                bool leftZero = (i == 0) || (nums[i - 1] == 0);
                bool rightZero = (i == n - 1) || (nums[i + 1] == 0);
                if (leftZero && rightZero) cntIsolatedNeg++;
            }
            if (nums[i] != 0) cntNZ++;
        }
        if (cntNZ == cntNeg && cntNeg == cntIsolatedNeg) return 0;

        // Edge case: length 2 and at least one zero
        if (n == 2 && (nums[0] == 0 || nums[1] == 0))
            return std::max(nums[0], nums[1]);

        // Regular logic: split by zeroes & handle segments
        std::vector<int> products;
        int k = 1, t = 0;
        products.push_back(k);
        std::vector<int> zeros;
        int j = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeros.push_back(i);
                j++;
                t++;
                products.push_back(1);
            } else {
                products[t] = products[t] * nums[i];
            }
        }

        int ans = INT_MIN, segStart = 0;
        for (int seg = 0; seg < products.size(); seg++) {
            int segProd = products[seg];
            int segEnd = (seg < zeros.size()) ? zeros[seg] : n;
            if (segProd > 0 && segProd > ans) {
                ans = segProd;
            } else if (segProd < 0) {
                int maxNegProd = maxNegSubarrayProduct(nums, segStart, segEnd);
                ans = std::max(ans, maxNegProd);
            }
            segStart = segEnd + 1;
        }

        // Make sure all singles (esp. zeros or negatives) are considered
        for (int i = 0; i < n; ++i) ans = std::max(ans, nums[i]);
        return ans;
    }
};

