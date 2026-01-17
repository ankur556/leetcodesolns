class Solution {
public:
    bool judgeCircle(string moves) {
        int rl=0;
        int ud=0;
        for(char c: moves){
            if(c=='L'){rl--;}
            else if(c=='R'){rl++;}
            else if(c=='U'){ud++;}
            else{ud--;}
        }
        return(rl==0&&ud==0);
    }
};
