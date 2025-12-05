class Solution {
public:
    int singleNumber(vector<int>& nums) {
      sort(nums.begin(),nums.end());
    long long i=0;
    while(i<nums.size()-1){
        if(nums[i]==nums[i+1]){i=i+2;}
        else return nums[i];
      } 
      return nums[nums.size()-1]; 
    }
};
