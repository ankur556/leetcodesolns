class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0); // Much faster than unordered_map
        int left = 0;
        int max_freq = 0;
        int max_len = 0;

        for (int right = 0; right < s.length(); right++) {
            // Add the new character to our window and update the historical max frequency
            counts[s[right] - 'A']++;
            max_freq = max(max_freq, counts[s[right] - 'A']);
            if ((right - left + 1) - max_freq > k) {
                counts[s[left] - 'A']--;
                left++; 
            }
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};
