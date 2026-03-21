class Solution {
public:
    string truncateSentence(string s, int k) {
        string sol;
        for(int i=0;i<s.size();i++){
            if(i<s.size()&&s[i]==' '){
                while(s[i]==' '){i++;}
            }
            while(i<s.size()&&s[i]!=' '){sol.push_back(s[i]);i++;}
            k--;
            if(k==0){break;}
            sol.push_back(' ');
        }
        return sol;
    }
};
