class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int rs=0;
        int ls=0;
        int ud=0;
        for(char c:moves){if(c=='L'){ls++;}else if(c=='R'){rs++;}else{ud++;}}
        return abs(ls-rs)+ud;
    }
};
