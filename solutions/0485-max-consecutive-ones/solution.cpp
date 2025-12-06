class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr=0;
        int max=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){curr++;}
            else{curr=0;}
            if(curr>max){max=curr;}
        }
        return max;
    }
};
