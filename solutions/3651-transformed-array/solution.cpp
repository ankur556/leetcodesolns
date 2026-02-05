class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> sol;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){sol.push_back(nums[i]);}
            else if(nums[i]>0){sol.push_back(nums[(i+nums[i])%nums.size()]);}
            else{sol.push_back(nums[((i + nums[i]) % (int)nums.size() + (int)nums.size()) % (int)nums.size()]);}
        }
        return sol;
    }
};
