class Solution {
public:
    bool canCross(vector<int>& stones) {
        queue<pair<int,int>> q;
        vector<vector<int>> vis(stones.size(),vector<int>(stones.size()));
        if(stones[1]==1){q.push({1,1});}
        while(!q.empty()){
            int a1=q.front().first;
            int lj=q.front().second;q.pop();
            if(a1==stones.size()-1){return true;}
            for(int i=a1+1;i<stones.size();i++){
                if(abs(stones[i]-stones[a1]-lj)<=1){if(vis[i][stones[i]-stones[a1]]==0){q.push({i,stones[i]-stones[a1]});vis[i][stones[i]-stones[a1]]=1;}}
                else if(stones[i]>stones[a1]+lj+1){break;}
            }
        }
        return false;
    }
};