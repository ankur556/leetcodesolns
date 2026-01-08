class Solution {
public:
    string removeOuterParentheses(string s) {
        int a=0;
        string sol;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){a++;
            if(a==1){continue;}
            else{sol.push_back(s[i]);}}
            else{
                a--;
                if(a==0){continue;}
                else{sol.push_back(s[i]);}
            }
        }
        return sol;
    }
};
