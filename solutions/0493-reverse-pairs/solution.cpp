class Solution {
public:
    int merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low, right = mid + 1;
        int count = 0; // Local counter for this merge step

        // --- 1. COUNTING REVERSE PAIRS ---
        // We use a pointer 'j' for the right half.
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            // Keep moving 'j' as long as the condition holds.
            // Note: Use 2LL to cast to long long to prevent integer overflow!
            while (j <= high && arr[i] > 2LL * arr[j]) {
                j++;
            }
            // If arr[i] > 2 * arr[j], then everything from mid+1 to j-1 is a valid pair
            count += (j - (mid + 1));
        }

        // --- 2. STANDARD MERGING LOGIC ---
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }

        while (left <= mid) temp.push_back(arr[left++]);
        while (right <= high) temp.push_back(arr[right++]);

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return count;
    }

    int mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high) return 0;
        
        int mid = (low + high) / 2;
        int count = 0;
        
        // Count pairs in left half, right half, and across the split
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);
        
        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
