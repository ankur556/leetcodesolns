class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0; // tracks open '('
        int add = 0;     // counts needed '(' for unmatched ')'

        for (char c : s) {
            if (c == '(') {
                balance++;
            } else { // c == ')'
                if (balance > 0) {
                    balance--; // match with an '('
                } else {
                    add++; // need one '(' before this ')'
                }
            }
        }

        // add = unmatched ')', balance = unmatched '('
        return add + balance;
    }
};

