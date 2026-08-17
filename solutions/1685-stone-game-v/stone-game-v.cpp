class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> pre;
        int cur=0;
        for(int i : stoneValue){cur+=i;pre.push_back(cur);}
        vector<vector<int>> dp(n,vector<int>(n));
        for(int diff=1;diff<n;diff++){
            for(int i=0;i<n;i++){
                int top=i+diff;
                for(int j=i;j<top;j++){
                if(top>=n){break;}
                int l,r;
                if(i==0){l=pre[j];r=pre[top];}
                else{l=pre[j]-pre[i-1];r=pre[top]-pre[i-1];}
                r-=l;
                if(l>r){
                    dp[i][top]=std::max(dp[i][top],r+dp[j+1][top]);
                }
                else if(r>l){
                    dp[i][top]=std::max(dp[i][top],dp[i][j]+l);
                }
                else{
                    dp[i][top]=std::max(dp[i][top],std::max(dp[i][j],dp[j+1][top])+l);
                }
                }
                
            }
        }
        /*for(int i=0;i<n;i++){
            for(int j= i+1;j<n;j++){
                cout<<i<<" "<<j<<" "<<pre[i]<<" "<<pre[j]<<" "<<dp[i][j]<<endl;
            }
        }*/
        return dp[0][n-1];
    }
};