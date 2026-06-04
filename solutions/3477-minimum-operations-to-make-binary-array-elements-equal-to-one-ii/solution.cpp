class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops=0;
        for(int i=0;i<nums.size();i++){if(nums[i]==0&&ops%2==0){ops++;}else if(nums[i]==1&&ops%2==1){ops++;}}
        return ops;
    }
};
