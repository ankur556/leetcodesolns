class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int r=nums.size();
        int l=0;
        
        if(nums.size()==1){return 0;}
        /*else if(nums.size()==2){
            if(nums[0]>nums[1]){return 0;}
            else{return 1;}
        }*/
        if(nums[0]>nums[1]){return 0;}
        if(nums[nums.size()-1]>nums[nums.size()-2]){return nums.size()-1;}
        int mid=l+(r-l)/2;
        while(l<r){
            mid=l+(r-l)/2;
            if(nums[mid+1]>nums[mid]){l=mid+1;}
            else if(nums[mid]<nums[mid-1]){r=mid;}
            else{return mid;}
        }
        return mid;
    }
};
