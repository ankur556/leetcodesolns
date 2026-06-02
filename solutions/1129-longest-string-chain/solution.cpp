class Solution {
public:
    bool is_val(vector<string>& words,int i,int j){
        if(words[j].size()!=words[i].size()+1){return false;}
        unordered_map<char,int> map;
        int p1=0;
        int p2=0;
        int uneq=0;
        for(int k=0;k<words[j].size();k++){
            if(words[i][p1]==words[j][p2]){p1++;p2++;}
            else if(uneq==0){p2++;uneq++;}
        }
        return p2==words[j].size();
    }
    static bool sorti(const string &s1, const string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
     sort(words.begin(),words.end(),sorti); 
       vector<int> dp(words.size(),1);
       int n=words.size();
       //dp[0]=1;
       for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i]+1>dp[j]&&is_val(words,i,j)){dp[j]=dp[i]+1;}
            }
       }
       int max=0;
       for(int i=0;i<n;i++){
        if(dp[i]>max){max=dp[i];}
       }
       return max;
    }
};
