class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        // r scans through every element in the array
        for (int r = 0; r < nums.size(); r++) {
            // When we find a non-zero, swap it into the 'l' position
            if (nums[r] != 0) {
                swap(nums[l], nums[r]);
                l++; // Move the zero boundary forward
            }
        }
    }
};