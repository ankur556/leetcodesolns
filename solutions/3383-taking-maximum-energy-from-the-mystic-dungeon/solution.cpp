#include <vector>
#include <algorithm> // For std::max_element

class Solution {
public:
    int maximumEnergy(std::vector<int>& energy, int k) {
        int n = energy.size();
        for (int i = n - k - 1; i >= 0; --i) {
            energy[i] += energy[i + k];
        }
         return *max_element(energy.begin(), energy.end());
    }
};
