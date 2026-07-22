class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> priority;
        for (int i = 0; i < arr2.size(); i++) {
            priority[arr2[i]] = i;
        }

        // Pass a lambda comparator directly into std::sort
        sort(arr1.begin(), arr1.end(), [&](int a, int b) {
            bool hasA = priority.count(a);
            bool hasB = priority.count(b);

            // Both elements are in arr2: compare by their index order
            if (hasA && hasB) {
                return priority[a] < priority[b];
            }
            // Only a is in arr2: a comes first
            if (hasA) return true;
            // Only b is in arr2: b comes first
            if (hasB) return false;

            // Neither is in arr2: sort in ascending order
            return a < b;
        });

        return arr1;
    }
};