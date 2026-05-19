class Solution {
public:
    int secondHighest(string s) {
        int max=-1;
        int max2=-1;
        for(char c: s){
            if(c-'0'<10){
                if(c-'0'>max){max2=max;max=c-'0';}
                else if(c-'0'>max2&&c-'0'!=max){max2=c-'0';}
            }
        }
        return max2;
    }
};
