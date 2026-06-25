class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int c=0;
        int sol=0;
        for(int i=0;i<nums.size();i++){
            c=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]==target){c++;}
                else{c--;}
                if(c>0){sol++;}
            }
        }
        return sol;
    }
};
