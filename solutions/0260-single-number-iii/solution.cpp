class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i: nums){map[i]++;}
        vector<int> sol;
        for(int i:nums){if(map[i]==1){sol.push_back(i);}}
        return sol;
    }
};
