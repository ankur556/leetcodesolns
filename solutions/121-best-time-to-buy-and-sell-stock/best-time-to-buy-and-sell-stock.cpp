class Solution {
public:
    int maxProfit(vector<int>& nums) {
        if(nums.size()==0){return 0;}
        int min=nums[0];
        int max=nums[0];
        int sol=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<min){min=nums[i];}
            else if(sol<nums[i]-min){sol=nums[i]-min;}
        }
        return sol;
    }
};