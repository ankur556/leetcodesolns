class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool one=false;
        for(int i=0;i<nums.size();i++){if(nums[i]==1){one=true;}}
            for(int i=0;i<nums.size();i++){if(nums[i]>nums.size()){nums[i]=1;}else if(nums[i]<=0){nums[i]=1;}}
            if(!one){return 1;}
            else{
                for(int i=0;i<nums.size();i++){int idx = abs(nums[i]) - 1;nums[idx] = -abs(nums[idx]);}
            }
            for(int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return nums.size()+1;
        
    }
};
