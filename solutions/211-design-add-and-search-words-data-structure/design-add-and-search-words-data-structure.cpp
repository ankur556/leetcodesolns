class WordDictionary {
private:
    // Store words grouped by their length (max length is 25)
    unordered_set<string> wordsByLen[26];

    bool match(const string& pattern, const string& word) {
        for (int i = 0; i < pattern.size(); i++) {
            if (pattern[i] != '.' && pattern[i] != word[i]) {
                return false;
            }
        }
        return true;
    }

public:
    WordDictionary() {}

    void addWord(string word) {
        wordsByLen[word.size()].insert(word); // Instant O(1) insertion
    }

    bool search(string word) {
        int len = word.size();
        
        // Fast path: Exact match lookup if no wildcards
        if (word.find('.') == string::npos) {
            return wordsByLen[len].count(word);
        }

        // Wildcard path: Only compare against words of the SAME length
        for (const string& w : wordsByLen[len]) {
            if (match(word, w)) return true;
        }

        return false;
    }
};