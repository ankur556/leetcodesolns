class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        // 1. Create a copy and sort it
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        // 2. Define pointers for the two halves
        // 'j' points to the end of the smaller half (bottom left)
        // 'k' points to the end of the larger half (top right)
        int j = (n - 1) / 2; 
        int k = n - 1;
        
        // 3. Fill the original array
        for (int i = 0; i < n; i++) {
            // If i is odd (1, 3, 5...), we need a LARGE number
            if (i % 2 == 1) {
                nums[i] = sorted[k];
                k--;
            } 
            // If i is even (0, 2, 4...), we need a SMALL number
            else {
                nums[i] = sorted[j];
                j--;
            }
        }
    }
};
