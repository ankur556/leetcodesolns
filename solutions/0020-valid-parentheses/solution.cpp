class Solution {
public:
    bool isValid(string s) {
        stack<int> a;
        for(char c:s){
            if(c=='('){a.push(c);}
            else if(c=='{'){a.push(c);}
            else if(c=='['){a.push(c);}
            else if(c==')'){if(a.empty()){return false;}else if(a.top()=='('){a.pop();}else{return false;}}
            else if(c=='}'){if(a.empty()){return false;}else if(a.top()=='{'){a.pop();}else{return false;}}
            else if(c==']'){if(a.empty()){return false;}else if(a.top()=='['){a.pop();}else{return false;}}
        }
        return a.empty();
    }
};
