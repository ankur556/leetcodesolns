class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> sol;
        int cur=nums[0];
        for(int i=0;i<nums.size();i++){
            while(cur<nums[i]){sol.push_back(cur);cur++;}
            cur=nums[i]+1;
        }
        return sol;
    }
};