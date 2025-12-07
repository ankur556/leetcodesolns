class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> vals;
        
        for(const string& t : tokens) {
            // Check if token is an operator
            if(t == "+" || t == "-" || t == "*" || t == "/") {
                // Pop the top two elements
                int a = vals.top(); vals.pop(); // This is the right-hand operand
                int b = vals.top(); vals.pop(); // This is the left-hand operand
                
                if(t == "+") {
                    vals.push(b + a);
                } else if(t == "-") {
                    vals.push(b - a); // Order matters!
                } else if(t == "*") {
                    vals.push(b * a);
                } else if(t == "/") {
                    vals.push(b / a); // Order matters!
                }
            } 
            // If it's not an operator, it's a number
            else {
                vals.push(stoi(t));
            }
        }
        return vals.top();
    }
};
