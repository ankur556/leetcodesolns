class Solution {
public:
    int hammingDistance(int x, int y) {
        int k=x^y;
        int sol=0;
        while(k>0){
            if(k%2==1){sol++;}k=k/2;
        }
        return sol;
    }
};
