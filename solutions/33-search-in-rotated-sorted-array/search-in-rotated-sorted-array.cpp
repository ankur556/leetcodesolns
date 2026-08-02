class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int mid=l+(r-l)/2;
        while(l<r){
            mid=l+(r-l)/2;
            if(nums[mid]<nums[r]){
                if(nums[r]<target||nums[mid]>target){r=mid;}
                else{l=mid+1;}
            }
            else{
                if(nums[mid]<target||nums[l]>target){l=mid+1;}
                else{r=mid;}
            }
            if(nums[l]==target){return l;}
            if(nums[mid]==target){return mid;}
        }
        if(nums[l]==target){return l;}
        if(nums[mid]==target){return mid;}
        else{return -1;}
    }
};