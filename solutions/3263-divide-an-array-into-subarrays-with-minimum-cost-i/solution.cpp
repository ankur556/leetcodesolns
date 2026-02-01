class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int sol=nums[0];

            int min1=1;
            int min2=2;
            for(int i=1;i<nums.size();i++){if(nums[i]<nums[min1]){min1=i;}}
            if(min1==min2){min2=1;}
            for(int i=1;i<nums.size();i++){if(i==min1){continue;}else if(nums[i]<nums[min2]){min2=i;}}
            return sol+nums[min1]+nums[min2];
        
        
    }
};
