class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size()));
        //dp[0][0]=1;
        int sol=0;
        bool f=false;
        for(int i=0;i<text1.size();i++){
            if(text1[i]==text2[0]){f=true;}
            if(f)dp[i][0]=1;
            else dp[i][0]=0;
            sol=max(sol,dp[i][0]);
        }
        f=false;
        for(int i=0;i<text2.size();i++){
            if(text2[i]==text1[0]){f=true;}
            if(f)dp[0][i]=1;
            else dp[0][i]=0;
            sol=max(sol,dp[0][i]);
        }
       // int sol=0;
        for(int i=1;i<text1.size();i++){
            for(int j=1;j<text2.size();j++){
                if(text1[i]==text2[j]){dp[i][j]=dp[i-1][j-1]+1;}
                else{dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);}
                sol=max(sol,dp[i][j]);
            }
        }
        return sol;
    }
};