class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
       vector<pair<int,int>> dp(nums.size(),{1,1});
       for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[i].first<=dp[j].first){
                        dp[i]=dp[j];
                        dp[i].first++;
                    }
                    else if(dp[i].first==dp[j].first+1){
                        dp[i].second+=dp[j].second;
                    }
                }
            }
       }
       int max=0;
       for(int i=0;i<dp.size();i++){
        if(dp[i].first>max){max=dp[i].first;}
       }
       int sol=0;
       for(int i=0;i<dp.size();i++){
        if(dp[i].first==max){sol+=dp[i].second;}
       }
       return sol;
       //finally found the max size for the dp in nsq
       //now we start from the end and we count the no of the subseq of this size we start calc for each possible element the seq ends at and we multiple each element in that corrospondence if we had 1 end element nsq soln was simple how do i do it with nsq with multiple possible ends??

    }
};