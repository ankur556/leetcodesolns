class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        // Define the keyboard rows as sets for O(1) lookups
        string row1 = "qwertyuiopQWERTYUIOP";
        string row2 = "asdfghjklASDFGHJKL";
        string row3 = "zxcvbnmZXCVBNM";
        
        // Use an array to map characters to their row index (0, 1, or 2)
        // Since ASCII is small (0-127), a vector of size 128 works well.
        vector<int> charToRow(128); 
        
        for(char c : row1) charToRow[c] = 1;
        for(char c : row2) charToRow[c] = 2;
        for(char c : row3) charToRow[c] = 3;
        
        vector<string> result;
        
        for(string word : words) {
            bool valid = true;
            // Get the row of the first character
            int row = charToRow[word[0]];
            
            // Check if all other characters match that same row
            for(int i = 1; i < word.size(); i++) {
                if(charToRow[word[i]] != row) {
                    valid = false;
                    break;
                }
            }
            
            if(valid) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};
