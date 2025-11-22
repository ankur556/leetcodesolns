class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size()<=0){return 0;}
        int max=nums[0];
        int min=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max){max=nums[i];}
            if(nums[i]<min){min=nums[i];}
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
ans=ans+nums[i]-min;
        }
        return ans;
    }
};
