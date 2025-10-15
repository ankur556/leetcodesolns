#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> a;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                a.push('(');
            } else if (s[i] == '[') {
                a.push('[');
            } else if (s[i] == '{') {
                a.push('{');
            } else if (s[i] == ']' && !a.empty() && a.top() == '[') {
                a.pop();
            } else if (s[i] == '}' && !a.empty() && a.top() == '{') {
                a.pop();
            } else if (s[i] == ')' && !a.empty() && a.top() == '(') {
                a.pop();
            } else {
                return false;
            }
        }
        return a.empty();
    }
};
