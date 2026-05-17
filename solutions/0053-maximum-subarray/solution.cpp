class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        int sol=-1e7;
        int sum_l=0;
        int sum_r=0;
        for(int i=0;i<nums.size();i++){
            sum_l+=nums[i];
            if(sum_l>sol){sol=sum_l;}
            if(sum_l<0){l=i;sum_l=0;}
        }
        for(int i=0;i<nums.size()-1;i++){
            sum_r+=nums[nums.size()-1-i];
            if(sum_r>sol){sol=sum_r;}
            if(sum_r<0){r=nums.size()-1-i;sum_r=0;}
        }
        int sum_m=0;
        if(l>r){return sol;}
        else{
            for(int i=l;i<r+1;i++){
                sum_m+=nums[i];
            }
            return max(sol,sum_m);
        }

    }
};
