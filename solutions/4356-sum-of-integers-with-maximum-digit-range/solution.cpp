class Solution {
public:
    int f(int n){
        int max=n%10;int min=n%10;
        while(n>0){
            if(n%10>max){max=n%10;}
            if(n%10<min){min=n%10;}
            n/=10;
        }
        //cout<<max;cout<<min;
        return max-min;
    }
    int maxDigitRange(vector<int>& nums) {
        int sol=0;
        int max=0;
        for(int i: nums){if(f(i)>max){max=f(i);}}
        for(int i: nums){if(f(i)==max){sol+=i;}}
        return sol;
    }
};
