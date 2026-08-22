class Solution {
public:
    bool checkDivisibility(int n) {
        int mul=1;int sum=0;
        int temp=n;
        while(n>0){
            mul*=(n%10);sum+=(n%10);n/=10;
        }
        //cout<<mul<<sum<<endl;
        return ((temp)%(mul+sum))==0;
    }
};