class Solution {
public:
    int minDistance(string word1, string word2) {
       // if(word1.size()>=2*word2.size()){return word1.size()-word2.size();}
        if(word1.size()==0){return word2.size();}
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1));
        for(int i=0;i<=word1.size();i++){dp[i][0]=i;}
        for(int j=0;j<=word2.size();j++){dp[0][j]=j;}
       // if(word1[0]!=word2[0]){dp[0][0]=1;}
        for(int i=1;i<word1.size()+1;i++){
            for(int j=1;j<word2.size()+1;j++){
                    if(word1[i-1]==word2[j-1]){dp[i][j]=dp[i-1][j-1];}
                    else{
                        dp[i][j]=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
                    }
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};