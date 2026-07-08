class Solution {
public:
    int minBitFlips(int start, int goal) {
        int sol=0;
        while(start>0||goal>0){
            sol+=((start%2)^(goal%2));start/=2;goal/=2;
        }
        return sol;
    }
};