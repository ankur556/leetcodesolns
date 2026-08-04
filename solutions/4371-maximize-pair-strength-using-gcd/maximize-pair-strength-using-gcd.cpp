class Solution {
public:
    long long fxn(int a1,int b1){
       long long gc=gcd(a1,b1);
       a1=a1/gc;b1=b1/gc;
       return 1LL*a1*b1;
    }
    long long maxPairStrength(vector<int>& nums) {
    long long sol=0;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            sol=max(sol,fxn(nums[i],nums[j]));
        }
    }    
    return sol;  
    }
};