class Solution {
public:
    int digitFrequencyScore(int n) {
        string a=to_string(n);
        int sol=0;
        for(char & c: a){sol+=((c-'0'));}
        return sol;
    }
};
