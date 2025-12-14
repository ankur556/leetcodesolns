#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        stack<int> s;
        int third = INT_MIN; // This represents nums[k] (the '2' in 1-3-2)

        // Iterate from Right to Left
        for (int i = n - 1; i >= 0; i--) {
            // Case 1: We found our '1' (nums[i])
            // If the current number is smaller than the largest valid '2' we've found...
            if (nums[i] < third) {
                return true;
            }

            // Case 2: We found a potential '3' (nums[j])
            // If current number is bigger than stack top, it means the stack top
            // is a valid '2' for this '3'. We pop the stack to find the LARGEST valid '2'.
            while (!s.empty() && nums[i] > s.top()) {
                third = s.top(); 
                s.pop();
            }

            // Push current number as a candidate for '3'
            s.push(nums[i]);
        }
        return false;
    }
};
