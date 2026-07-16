class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long maxVal=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxVal){maxVal=nums[i];}
            nums[i]=(gcd(maxVal,nums[i]));
        }
        sort(nums.begin(),nums.end());
        long long Sol=0;
        for(int i=0;i<nums.size()/2;i++){
            Sol+=(gcd(nums[i],nums[nums.size()-1-i]));
        }
        return Sol;
    }
};