class Solution {
public:
    bool detectCapitalUse(string word) {
        bool caps_after_start = false; // Only track caps that appear after the first letter
        bool small = false;
        
        for(int i = 0; i < word.size(); i++) {
            // Fix ASCII: Uppercase is <= 90 ('Z' is 90)
            if(int(word[i]) <= 90) { 
                if(i > 0) caps_after_start = true; 
            } 
            // Fix ASCII: Lowercase is > 90 ('a' is 97)
            else { 
                small = true; 
            }
        }
        
        // Returns false ONLY if we have smalls AND a capital after the start (like "FlaG")
        return !(caps_after_start && small);
    }
};
