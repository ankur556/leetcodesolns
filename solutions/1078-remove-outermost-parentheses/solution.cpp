class Solution {
public:
    string removeOuterParentheses(string s) {
       int c=1;
       string sol;
       bool flag=false;
       for(int i=1;i<s.size();i++){
        if(s[i]=='('){c++;}
        else{c--;}
        if(c==0||(c==1&&s[i]=='(')){}
        else{sol.push_back(s[i]);}
       } 
       return sol;
    }
};
