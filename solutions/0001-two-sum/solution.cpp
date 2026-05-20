class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> a;
        for(int i=0;i<nums.size();i++){
            a[nums[i]]=i+1;
        }vector<int> sol;
        for(int i=0;i<nums.size();i++){
            if(a[target-nums[i]]>0&&a[target-nums[i]]!=i+1){sol.push_back(i);sol.push_back(a[target-nums[i]]-1);return sol;}
        }
        return sol;
    }
};
