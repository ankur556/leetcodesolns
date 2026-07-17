class Solution {
public:
    int minCut(string s) {
        if(s.size()==0){return 0;}
       else if(s == string(s.rbegin(), s.rend())){return 0;}
        else if(s.size()==2){
            if(s[0]==s[1]){return 0;}
            else{return 1;}
        }
        vector<int> dp(s.size(),1e5);
        dp[0]=1;
        for(int i=0;i<s.size();i++){dp[i]=i;}
        vector<vector<bool>> ispal(s.size(),vector<bool>(s.size()));
        for(int i=0;i<s.size();i++){ispal[i][i]=true;}
        for(int i=1;i<s.size();i++){if(s[i]==s[i-1]){ispal[i-1][i]=true;}}//cout<<i-1<<" "<<i<<endl;}}
       /* for(int j=0;i<s.size();i++){
            for(int j=2;j<s.size()-i;j++){
                if(s[j+i]==s[i]&&ispal[i+1][j+i-1]){ispal[i][j+i]=true;cout<<i<<" "<<j+i<<endl;}
            }
        }*/
        for(int diff=2;diff<s.size();diff++){
            for(int i=0;i<s.size()-diff;i++){
                if(ispal[i+1][i+diff-1]&&s[i]==s[i+diff]){ispal[i][i+diff]=true;}//cout<<i<<i+diff<<endl;}
            }
        }
       // cout<<"the part to debug"<<endl;
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<=i;j++){
                if(ispal[j][i]&&j==0){dp[i]=0;}
                else if(ispal[j][i]){dp[i]=min(dp[i],dp[j-1]+1);}
                else if(j==0){dp[i]=min(dp[i],i);}
                else{dp[i]=min(dp[i],dp[j-1]+i-j+1);}
               // cout<<i<<" "<<j<<" "<<dp[i]<<endl;
            }
        }
    return dp[dp.size()-1];
    }
};