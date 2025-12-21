class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2){return 0;}
        else if(nums.size()==2){
            if(nums[0]>nums[1]){swap(nums[0],nums[1]);}
            return nums[1]-nums[0];
        }
        else{
            sort(nums.begin(),nums.end());
            int sol=0;
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i+1]-nums[i]>sol){sol=nums[i+1]-nums[i];}
            }
            return sol;
        }
    }
};
