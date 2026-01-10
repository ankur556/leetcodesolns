class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> map1;
        for(int i: nums){map1[i]++;}
        for(int i: nums){if(map1[i]!=1){return i;}}
        return nums[nums.size()-1];
    }
};
