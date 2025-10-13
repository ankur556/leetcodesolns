bool isAnagram(const string& a, const string& b) {
    if (a.length() != b.length()) return false;
    string a_sorted = a, b_sorted = b;
    sort(a_sorted.begin(), a_sorted.end());
    sort(b_sorted.begin(), b_sorted.end());
    return a_sorted == b_sorted;
}
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        string prev = "";
        for (auto &word : words) {
            string sorted_word = word;
            sort(sorted_word.begin(), sorted_word.end());
            if (sorted_word != prev) {
                ans.push_back(word);
                prev = sorted_word;
            }
        }
        return ans;
    }
};

