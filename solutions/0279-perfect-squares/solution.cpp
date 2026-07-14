class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,1e3);
        int k=sqrt(n);
        if(k*k==n){return 1;}
        for(int i=0;i<dp.size();i++){
            dp[i]=i;
        }
        for(int i=0;i<=k;i++){
            int sq=i*i;
            for(int j=sq;j<dp.size();j++){
                dp[j]=min(dp[j],dp[j-sq]+1);
            }
        }
        return dp[dp.size()-1];
    }
};
