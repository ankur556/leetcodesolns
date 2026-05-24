class Solution {
public:
    bool canPartition(vector<int>& nums) {
    int sum=0;
    for(int i:nums){sum+=i;}
    if(sum%2==1){return false;}
    vector<bool> dp(sum/2+1,false);
    dp[0]=true;
    if (nums[0] < sum/2+1) {dp[nums[0]] = true;//cout<<nums[0]<<endl;
    }
    for(int i=1;i<nums.size();i++){
        for(int j=sum/2;j>=nums[i];j--){
            if(dp[j-nums[i]]==true){dp[j]=true;//cout<<j;cout<<i<<endl;
            }
        }
    }
    return dp[(sum+1)/2];
    }
};
