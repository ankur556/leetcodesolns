class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int i = 0;
        int j = n - 1;

        // Strategy: The max distance must involve either the 
        // first house or the last house.

        // 1. Check from the end moving leftwards
        while (colors[j] == colors[0]) {
            j--;
        }
        
        // 2. Check from the beginning moving rightwards
        while (colors[i] == colors[n - 1]) {
            i++;
        }

        // The answer is the maximum of these two possible spans
        // Distance 1: (n - 1) - i
        // Distance 2: j - 0
        return max(j, (n - 1) - i);
    }
};
