class Solution {
public:
    bool check(vector<int>& nums) {
        bool once=false;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]&&once){return false;}
            if(nums[i]<nums[i-1]){once=true;}
            
        }
        if(once&&nums[0]<nums[nums.size()-1]){return false;}
        return true;
    }
};
