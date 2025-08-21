class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        for(char c : s) {
            if(c == '{' || c == '(' || c == '[') {
                a.push(c);
            } 
            else {
                if(a.empty()) return false; // nothing to match
                char top = a.top();
                a.pop();
                if((c == ')' && top != '(') ||
                   (c == '}' && top != '{') ||
                   (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        return a.empty(); // valid only if no unmatched opening
    }
};

