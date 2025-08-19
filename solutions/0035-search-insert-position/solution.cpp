class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int smoll=0;
        int skonki=nums.size();
        int mid=0;
        if(target>nums[nums.size()-1]){return nums.size();}
        else if(target==nums[nums.size()-1]){return nums.size()-1;}
        else if(target<nums[0]){return 0;}
        else{
        for(int i=0;i<nums.size();i++){
            int mid=smoll+(skonki-smoll)/2;
            if(nums[mid]<=target&&target<nums[mid+1]){
            if(nums[mid]<target&&target<nums[mid+1]){return mid+1;}
            else if(nums[mid]==target){return mid;}
            else{continue;}
            }
            else if(nums[mid]<target){smoll=mid;}
            else if(nums[mid]>target){skonki=mid;}
        }}
        return nums.size();
    }
};
