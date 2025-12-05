#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    // Helper function to determine operator precedence
    int priority(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    // Helper function to perform the math
    int eval(int a, int b, char op) {
        if (op == '+') return a + b;
        if (op == '-') return a - b;
        if (op == '*') return a * b;
        if (op == '/') return a / b;
        return 0;
    }

    int calculate(string s) {
        stack<char> ops; // Stack for operators
        stack<int> nums; // Stack for numbers
        
        for (int i = 0; i < s.size(); i++) {
            // 1. Skip spaces
            if (s[i] == ' ') continue;

            // 2. Handle Numbers (including multi-digit)
            if (isdigit(s[i])) {
                long long num = 0; // Use long long to prevent overflow during parsing
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                nums.push(num);
                i--; // Decrement i because the for-loop will increment it again
            } 
            // 3. Handle Operators
            else {
                // While top of stack has higher or equal precedence, apply that operator first
                while (!ops.empty() && priority(ops.top()) >= priority(s[i])) {
                    int val2 = nums.top(); nums.pop(); // Right operand
                    int val1 = nums.top(); nums.pop(); // Left operand
                    char op = ops.top(); ops.pop();
                    
                    nums.push(eval(val1, val2, op));
                }
                // Push the current operator onto the stack
                ops.push(s[i]);
            }
        }

        // 4. Final Cleanup: Process remaining operators in the stack
        while (!ops.empty()) {
            int val2 = nums.top(); nums.pop();
            int val1 = nums.top(); nums.pop();
            char op = ops.top(); ops.pop();
            
            nums.push(eval(val1, val2, op));
        }

        return nums.top();
    }
};
