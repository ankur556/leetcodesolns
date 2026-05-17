class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int r=nums.size()-1;
        int l=0;
        vector<int> sol;
        while(l<r){
            if(nums[l]+nums[r]==target){sol.push_back(l+1);sol.push_back(r+1);break;}
            else if(nums[l]+nums[r]<target){l++;}
            else{r--;}
        }
        return sol;
    }
};
