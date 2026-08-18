class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        priority_queue<vector<int>> pq;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                pq.push({matrix[i][j],i,j});
            }
        }
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
        while(!pq.empty()){
            int x=pq.top()[1];
            int y=pq.top()[2];
            int top_val=pq.top()[0];
            pq.pop();
            for(auto a : dirs){
                int x1=x+a.first;
                int y1=y+a.second;
                if(x1>=0 && x1<n && y1>=0 && y1<m){
                   if(matrix[x1][y1]>matrix[x][y]){ dp[x][y]=std::max(dp[x][y],1+dp[x1][y1]);}
                   else {
                    dp[x][y]=std::max(dp[x][y],1);
                   }
                }
            }
        }
        int sol=1;
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        sol=std::max(sol,dp[i][j]);
                    }
        }
        return sol;
    }
};