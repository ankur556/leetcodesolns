class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int> ap_prior;
        int sol=1;
        ap_prior[nums[0]]++;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                if(ap_prior[nums[i]]==0){
                    sol++;ap_prior[nums[i]]++;
                }
                else if(ap_prior[nums[i]]==1){
                    sol--;ap_prior[nums[i]]++;
                }
            }
        }
        return sol;
    }
};