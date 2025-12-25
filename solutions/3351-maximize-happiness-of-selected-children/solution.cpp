class Solution {
public:
    long long maximumHappinessSum(vector<int>& nums, int k) {
        long long sol=0;
        long long diff=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        //if(nums.size()==k){k--;}
        for(int i=n-1;i>=n-k;i--){
            if(nums[i]-diff>=0){sol+=nums[i]-diff;}
            else{continue;}
            diff++;
        }
        return sol;
    }
};
