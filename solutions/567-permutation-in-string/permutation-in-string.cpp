#include <vector>
#include <string>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        if (n1 > n2) return false;

        // Count frequency of characters in s1 and the first window of s2
        std::vector<int> cnt1(26, 0), cnt2(26, 0);
        for (int i = 0; i < n1; i++) {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }

        if (cnt1 == cnt2) return true;

        // Slide the window across s2
        for (int i = n1; i < n2; i++) {
            // Add new character entering the window
            cnt2[s2[i] - 'a']++;
            // Remove old character leaving the window
            cnt2[s2[i - n1] - 'a']--;

            // Check if current window matches s1's character frequencies
            if (cnt1 == cnt2) return true;
        }

        return false;
    }
};