class Solution {
public:
    int maxDepth(string s) {
        int cur=0;
        int sol=0;
        for(char c: s){
            if(c=='('){cur++;}
            else if(c==')'){cur--;}
            if(cur>sol){sol=cur;}
        }
        return sol;
    }
};
