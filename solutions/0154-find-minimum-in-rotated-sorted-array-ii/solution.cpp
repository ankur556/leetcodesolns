class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==0){return 0;}
      int min=nums[0];
      for(int i: nums){if(i<min){min=i;}}
    return min;
    }
};
