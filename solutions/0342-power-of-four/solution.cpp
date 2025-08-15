class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0){return false;}
        else{
        bool ans=true;
        for(int i=0;i<16;i++){
            if(n%4==0){n=n/4;}
            else if(n==1){return true;}
            else if(n%4!=0){return false;}
        }
        return true;}
    }
};
