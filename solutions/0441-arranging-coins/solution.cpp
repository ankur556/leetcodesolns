class Solution {
public:
    int arrangeCoins(int n) {
        long long k=0;
        long long r=0;
        if(n==1){return 1;}
        while(n>=r){k++;r=(k)*(k+1)/2;}
        return k-1;
    }
};
