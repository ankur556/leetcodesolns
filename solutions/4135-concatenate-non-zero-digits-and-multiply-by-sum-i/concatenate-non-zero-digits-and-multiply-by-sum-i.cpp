class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long val=0;
        vector<int> vals;
        while(n>0){
            if(n%10){vals.push_back(n%10);sum+=n%10;}
            n/=10;
        }
        for(int i=vals.size()-1;i>=0;i--){
           val*=10; val+=vals[i];
        }
        return 1LL*sum*val;
    }
};