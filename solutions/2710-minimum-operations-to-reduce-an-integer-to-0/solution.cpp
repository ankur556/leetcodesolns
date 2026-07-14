class Solution {
public:
    int minOperations(int n) {
       int sol=0;
       while(n>0){
        if(n%2){
            if((n/2)%2){n++;}
            else{n--;}
            sol++;
        }
        else{n/=2;}
       } 
       return sol;
    }
};
