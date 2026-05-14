class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> a;
        for(auto i:wordDict){a[i]++;}
        vector<bool>dp(s.size()+1,false);
        dp[0]=true;
        for(int i=0;i<wordDict.size();i++){
            if(a[s.substr(0,i)]!=0){dp[i]=true;}
        }
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<i;j++){
                if(dp[j]==true&&a[(s.substr(j,i-j))]!=0){dp[i]=true;break;}
            }
        }
        return dp[dp.size()-1];
    }
};
