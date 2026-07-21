class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int cur=0;
        for(char c: s){cur+=c-'0';}
        vector<int> dp;
        int rn=0;
       // if(s[0]==0){rn=1;}
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){rn++;}
            else if(rn>0){dp.push_back(rn);rn=0;}
        }
       if(rn>0){dp.push_back(rn);rn=0;}
       int s1=0;
       for(int i=1;i<dp.size();i++){
        if(dp[i]+dp[i-1]>s1){s1=dp[i]+dp[i-1];}
       }
       return s1+cur;
    }
};