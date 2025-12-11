class Solution {
public:
    string removeDuplicateLetters(string s) {
        // 1. Count frequency so we know if a char appears "later"
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        // 2. Keep track if a char is currently in real_ans to avoid duplicates
        vector<bool> in_result(26, false);
        string real_ans = "";

        for (char c : s) {
            // We visited this char, so decrease its remaining count
            count[c - 'a']--;

            // If we already have this char in our answer, skip it
            if (in_result[c - 'a']) continue;

            // THE CONDITION TO REMOVE CHARACTERS:
            // 1. real_ans is not empty
            // 2. The last char in real_ans is BIGGER than current char 'c'
            // 3. The last char still has remaining copies later in string (count > 0)
            while (!real_ans.empty() && real_ans.back() > c && count[real_ans.back() - 'a'] > 0) {
                in_result[real_ans.back() - 'a'] = false; // Mark removed
                real_ans.pop_back(); // Remove it
            }

            // Add the current char
            real_ans.push_back(c);
            in_result[c - 'a'] = true;
        }
        
        return real_ans;
    }
};
