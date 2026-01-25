class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        if(k==1){return 0;}
        else if(nums.size()==1){return 0;}
        int sol=nums[k-1]-nums[0];
        for(int i=0;i<nums.size()-k+1;i++){
            if(nums[i+k-1]-nums[i]<sol){sol=nums[k+i-1]-nums[i];}
        }
        return sol;
    }
};
