class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]*=nums[i];
        }
        sort(nums.begin(),nums.end());
        long long sol=0;
        for(int i=0;i<nums.size()/2;i++){
            sol-=nums[i];
        }
        for(int i=nums.size()/2;i<nums.size();i++){
            sol+=nums[i];
        }
        return sol;
    }
};