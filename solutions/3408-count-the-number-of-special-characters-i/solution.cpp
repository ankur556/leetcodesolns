class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> cntl(26,0);
        vector<int> cntu(26,0);
        for(char c: word){
            if(c-'a'>=0&&c-'a'<26){cntl[c-'a']++;}
            else if(c-'A'>=0&&c-'A'<26){cntu[c-'A']++;}
        }
        int sol=0;
        for(int i=0;i<cntl.size();i++){
            if(cntl[i]>0&&cntu[i]>0){sol++;}
        }
        return sol;
    }
};
