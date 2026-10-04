class Solution {
public:
    int longestValidParentheses(string s) {
        int cnt=0;
        int sol=0;
        int open=0;
        int close=0;
        for(char c :s){if(c=='('){open++;}else if(c==')'){close++;}}
        int k=std::min(open,close);
        for(int i=0;i<s.size();i++){
           cnt=0;
            for(int j=i;j<std::min(int(s.size()),i+2*k);j++){
                if(s[j]=='('){cnt++;}
                else{
                    if(cnt==0){break;}
                    else{cnt--;}
                }
                if(cnt==0){sol=std::max(j-i+1,sol);}
            }
        }
        return sol;
    }
};