class Solution {
public:
    int titleToNumber(string c) {
        int sol=0;
        for(int i=0;i<c.size();i++){sol=sol*26;sol+=(c[i]-'A'+1);}
        return sol;
    }
};
