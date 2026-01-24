class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sol=0;
        for(int i=0;i<nums.size()/2;i++){
            if(nums[i]+nums[nums.size()-1-i]>sol){sol=nums[i]+nums[nums.size()-i-1];}
        }
        return sol;
    }
};
