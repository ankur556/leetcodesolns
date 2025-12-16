class Solution {
public:
    bool check(vector<int>& nums) {
        int drops=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]<nums[i]){drops++;}
        }
        if(nums[nums.size()-1]>nums[0]){drops++;}
        return drops<=1;
    }
};
