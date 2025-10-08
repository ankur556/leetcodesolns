class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans(spells.size(), 0);
        sort(potions.begin(), potions.end()); // Sort potions array

        for (int j = 0; j < spells.size(); ++j) {
            // Calculate the minimum required potion strength for the current spell
            // Use long long for required_potion_value to prevent overflow
            long long required_potion_value = (success + spells[j] - 1) / spells[j];

            int low = 0;
            int high = potions.size(); // 'high' is exclusive (one past the last element)
            int first_sufficient_potion_idx = potions.size(); // Default: no potion is sufficient

            // Binary search to find the first potion that is strong enough
            while (low < high) {
                int mid = low + (high - low) / 2;
                // If potions[mid] is sufficient (or stronger)
                if ((long long)potions[mid] >= required_potion_value) {
                    first_sufficient_potion_idx = mid; // This potion might be our answer, or an earlier one
                    high = mid; // Try to find an even earlier one in the left half
                } else {
                    // potions[mid] is too weak, need to look in the right half
                    low = mid + 1;
                }
            }
            // The number of successful pairs for the current spell is:
            // total number of potions - index of the first sufficient potion
            ans[j] = potions.size() - first_sufficient_potion_idx;
        }
        return ans;
    }
};
