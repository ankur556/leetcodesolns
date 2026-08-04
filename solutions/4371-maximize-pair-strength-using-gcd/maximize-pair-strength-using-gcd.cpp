class Solution {
public:
    long long fxn(int a1,int b1){
        long long a=a1;
        long long b=b1;
        return (long long)((long long)(a*b)/((long long)pow(gcd(a,b),2)));
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