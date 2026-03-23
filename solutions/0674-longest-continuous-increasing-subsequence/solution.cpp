class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int curr=1;int max=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]>nums[i]){curr++;}
            else{curr=1;}
            if(curr>max){max=curr;}
        }
        return max;
    }
};
