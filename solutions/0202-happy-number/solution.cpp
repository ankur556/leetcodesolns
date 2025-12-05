class Solution {
public:
    int sumsqs(int b){
        vector<int> a;
        while(b>0){
            a.push_back(b%10);b=b/10;
        }
        int sol=0;
        for(int i=0;i<a.size();i++){
            sol+=(a[i]*a[i]);
        }
        return sol;
    }
    bool isHappy(int n) {
        while(n>=3){
            n=sumsqs(n);
            if(n==1){return true;}
            else if(n==2){return false;}
            else if(n==4){return false;}
        }
        return n==1;
    }
};
