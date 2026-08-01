class Solution {
public:
    int reverse(int x1) {
        bool neg=false;
        long long x=x1;
        if(x<0){neg=true;x*=-1;}
        vector<int> helper;
        while(x>0){
            helper.push_back(x%10);x/=10;
        }
        long long sol=0;
        for(int i=0;i<helper.size();i++){
           sol*=10; sol+=helper[i];
        }
        if(!(pow(2,31)-1>sol&&-pow(2,31)<sol)){return 0;}
        if(neg){return -sol;}
        return sol;
    }
};