class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min=nums[0];
        int max=nums[0];
        for(int i:nums){
            if(i<min){min=i;}
            if(i>max){max=i;}
        }
        return gcd(min,max);
    }
};