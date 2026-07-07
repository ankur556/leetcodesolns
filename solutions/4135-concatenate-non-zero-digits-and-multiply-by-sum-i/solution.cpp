class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long t=1e9;
        long long val=0;
        while(t>0){
            int c;
            if(t>=10){c=(n%(10*t)-n%t)/t;}
            else{c=n%10;}
            if(c){val*=10;val+=c;sum+=c;}
            t/=10;
            cout<<c<<endl;
        }
        return 1LL*sum*val;
    }
};
