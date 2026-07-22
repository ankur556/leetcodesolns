class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (!st.count(endWord)) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1}); // {word, path_length}

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            if (word == endWord) return steps;

            // Generate all 1-character transformations
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    // O(1) set lookup
                    if (st.count(word)) {
                        st.erase(word); // Erasing acts as vis[word] = 1
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original; // Backtrack character
            }
        }
        return 0;
    }
};