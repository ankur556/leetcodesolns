class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string sol;
        for(char c:s){if(cnt!=0&&c=='('){sol.push_back(c);}if(c=='('){cnt++;}else{cnt--;}if(cnt!=0&&c==')'){sol.push_back(c);}}
        return sol;
    }
};
