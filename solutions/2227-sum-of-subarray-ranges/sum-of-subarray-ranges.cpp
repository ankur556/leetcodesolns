class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
       long long sol=0;
       int min=1e9+7;
       int max=-min;
        for(int i=0;i<nums.size();i++){
            min=nums[i];
            max=nums[i];
            for(int j=i;j<nums.size();j++){
                min=std::min(nums[j],min);
                max=std::max(nums[j],max);
                sol+=(max-min);
            }
        }
        return sol;
    }
};