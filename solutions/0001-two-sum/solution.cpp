class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> a;
        vector<int> sol;
        for(int i=1;i<nums.size();i++){
            if(nums[i]+nums[0]==target){sol.push_back(0);sol.push_back(i);break;}
            else{
                if(a[target-nums[i]]!=0){sol.push_back(a[target-nums[i]]);sol.push_back(i);break;}
            }a[nums[i]]=i;
        }
        return sol;
    }
};
