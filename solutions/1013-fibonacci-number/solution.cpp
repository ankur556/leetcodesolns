class Solution {
public:
int fiB(int n){
    if(n==1){return 1;}
    else if(n==0){return 0;}
    else{return fiB(n-1)+fiB(n-2);}
}
    int fib(int n) {
        return fiB(n);
    }
};
