class Solution {
public:
    bool judgeCircle(string moves) {
        int h=0;
        int l=0;
        for(char c: moves){if(c=='U'){h++;}else if(c=='D'){h--;}else if(c=='R'){l++;}else if(c=='L'){l--;}}
        return(h==0&&l==0);
    }
};
