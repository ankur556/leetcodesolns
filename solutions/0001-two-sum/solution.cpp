class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> a;
        for(int i=0;i<nums.size();i++){a[nums[i]]=i;}
        vector<int> sol;
        for(int i=1;i<nums.size();i++){if(nums[i]+nums[0]==target){sol.push_back(i);sol.push_back(0);return sol;}
        else if(a[target-nums[i]]!=i&&a[target-nums[i]]!=0){sol.push_back(i);sol.push_back(a[target-nums[i]]);return sol;}}
        sol.push_back(0);
        sol.push_back(nums.size()-1);
        return sol;
    }
};
