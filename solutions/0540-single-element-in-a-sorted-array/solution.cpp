class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int val=-1;
        if(nums.size()==1){return nums[0];}
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]||nums[i]==nums[i-1]){continue;}
            else{val=nums[i];}
        }
        if(val!=-1){return val;}
        else{
            if(nums[0]!=nums[1]){return nums[0];}
            else {return nums[nums.size()-1]; }
        }
    }
};
