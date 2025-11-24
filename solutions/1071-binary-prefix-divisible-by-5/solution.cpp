class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>ans(nums.size(),0);
        long long cur=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){cur=(2*cur+1)%5;nums[i]=cur;}
            else{cur=(2*cur)%5;nums[i]=cur;}
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]%5==0){ans[i]=true;}
            else{continue;}
        }
        return ans;
    }
};
