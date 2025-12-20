class Solution {
public:
    int singleNumber(vector<int>& nums) {
            unordered_map<int,int> map;
        for(int a : nums){map[a]++;}
        for(int a: nums){if(map[a]!=3){return a;}}
        return 0;
    }
};
