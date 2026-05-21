class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        for(char c: s){
            if(c=='('||c=='['||c=='{'){a.push(c);}
            else{
                if(c==')'){
                    if(a.empty()||a.top()!='('){return false;}
                    else{a.pop();}
                }
                if(c==']'){
                    if(a.empty()||a.top()!='['){return false;}
                    else{a.pop();}
                }
                if(c=='}'){
                    if(a.empty()||a.top()!='{'){return false;}
                    else{a.pop();}
                }
            if(!a.empty()){cout<<a.top();}
            }
        }
        return a.empty();
    }
};

