class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size()==3){
            return nums[0]*nums[1]*nums[2];
        }
        else{
            sort(nums.begin(),nums.end());
            if(nums[nums.size()-1]>=0){
            if(nums[0]*nums[1]>nums[nums.size()-2]*nums[nums.size()-3]){return nums[0]*nums[1]*nums[nums.size()-1];}
            else{return nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];}}
            else{return nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];}
        }
    }
};
