class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //we have target each time we do negetive the val becomes total sum - 2*neg vals
        //so totalsum-2*negvalues=target=>totalsum-negvalues=posvalues=target-negval
        //negval=(total-target)/2
        int sum=0;
        for(int i:nums){sum+=i;}
        if((abs(sum-target))%2==1){cout<<"return"<<endl;return 0;}
        vector<long long> dp(1001,0);
        dp[0]=1;
        if(target>sum){return 0;}
        int neg_val=(sum-target)/2;
        //int new_tar=target-neg_val;
        for(int i=0;i<nums.size();i++){
            for(int j=dp.size()-1;j>=0;j--){
                if(j>=nums[i]){dp[j]+=dp[j-nums[i]];}
                //if(j<dp.size()-nums[i]){dp[j]+=dp[j+nums[i]];}
            }
        }
        return dp[neg_val];
    }
};
