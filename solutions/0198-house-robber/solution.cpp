class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<=2){int max=0;
        for(int i:nums){if(i>max){max=i;}}
        return max;}
        vector<int> helper(nums.size(),0);
        helper[0]=nums[0];
        helper[1]=max(nums[1],nums[0]);
        for(int i=2;i<nums.size();i++){
            helper[i]=max(helper[i-2]+nums[i],helper[i-1]);
        }
        return (int)helper[helper.size()-1];
    }
};
