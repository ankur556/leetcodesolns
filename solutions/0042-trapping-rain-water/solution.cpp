class Solution {
public:
    int trap(vector<int>& nums) {
        int max_l=nums[0];int max_r=nums[nums.size()-1];
        int l=0;int r=nums.size()-1;
        int sol=0;
        while(l<r){
            max_l=max(max_l,nums[l]);
            max_r=max(max_r,nums[r]);
            if(max_l>=max_r){sol+=(max_r-nums[r]);r--;}
            else{sol+=(max_l-nums[l]);l++;}
        }
        return sol;
    }
};
