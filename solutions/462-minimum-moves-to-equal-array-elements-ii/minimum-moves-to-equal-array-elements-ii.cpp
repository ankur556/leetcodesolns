class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int median=nums[nums.size()/2];
        int sol=0;
        for(int & i : nums ){
            sol+=(abs(i-median));
        }
        return sol;
    }
};