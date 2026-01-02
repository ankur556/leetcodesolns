class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
    for(int i=0;i<nums.size()-2;i++){
        if(nums[i]==nums[i+1]){return nums[i];}
        else if(nums[i]==nums[i+2]){return nums[i];}
    }
     if(nums[nums.size()-2]==nums[nums.size()-1]){return nums[nums.size()-1];}
     else if(nums[0]==nums[nums.size()-1]){return nums[0];}
    return nums[0];
    }
};
