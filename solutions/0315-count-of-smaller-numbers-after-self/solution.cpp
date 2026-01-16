class Solution {
public:
    void merge(vector<pair<int, int>>& arr, vector<int>& count, int left, int mid, int right) {
        vector<pair<int, int>> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right) {
            // If the left element is smaller or equal, we close the "smaller" count 
            // for that element based on how many right-side elements were already placed.
            if (arr[i].first <= arr[j].first) {
                count[arr[i].second] += (j - (mid + 1));
                temp[k++] = arr[i++];
            } else {
                // The right element is smaller, so we just move it.
                temp[k++] = arr[j++];
            }
        }

        // Clean up remaining elements
        while (i <= mid) {
            count[arr[i].second] += (j - (mid + 1));
            temp[k++] = arr[i++];
        }
        while (j <= right) {
            temp[k++] = arr[j++];
        }

        for (int p = 0; p < temp.size(); p++) {
            arr[left + p] = temp[p];
        }
    }

    void mergeSort(vector<pair<int, int>>& arr, vector<int>& count, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(arr, count, left, mid);
        mergeSort(arr, count, mid + 1, right);
        merge(arr, count, left, mid, right);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0);
        vector<pair<int, int>> arr; // {value, original_index}

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        mergeSort(arr, count, 0, n - 1);
        return count;
    }
};
