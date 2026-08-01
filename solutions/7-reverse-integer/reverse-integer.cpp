class Solution {
public:
    int reverse(int x1) {
        bool neg=false;
        long long x=x1;
        if(x<0){neg=true;x*=-1;}
        vector<int> helper;
        long long sol=0;
        while(x>0){
            sol*=10; sol+=x%10;x/=10;
        }
        
        if(!(pow(2,31)-1>sol&&-pow(2,31)<sol)){return 0;}
        if(neg){return -sol;}
        return sol;
    }
};