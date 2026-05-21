class Solution {
public:
    int minBitFlips(int start, int goal) {
        int sol;
        int a=start^goal;
        while(a>0){
            sol+=a%2;
            a/=2;
        }
        return sol;
    }
};
