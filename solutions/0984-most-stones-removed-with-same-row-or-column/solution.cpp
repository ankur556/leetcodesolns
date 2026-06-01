class Solution {
public:
    set<pair<int,int>> s;
    int bfs(map<pair<int,int>,vector<pair<int,int>>> &mp, pair<int,int> p){
        
        if(s.count({p.first,p.second})!=0)
            return 0;
        
        int cnt=0;
        queue<pair<int,int>> q;
        q.push(p);
        
        while(q.size()>=1){
            int len = q.size();
            cnt+=len;
            for(int i=0;i<len;i++){
                pair<int,int> temp = q.front();
                q.pop();
                s.insert({temp.first,temp.second});
                for(auto x: mp[temp]){
                    if(s.count({x.first,x.second})==0){
                        q.push({x.first,x.second});
                        s.insert({x.first,x.second});
                    }
                }
            }
        }
        return cnt-1;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        map<pair<int,int>,vector<pair<int,int>>> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j&&(stones[j][0] == stones[i][0]||stones[j][1] == stones[i][1]))
                mp[{stones[i][0],stones[i][1]}].push_back({stones[j][0],stones[j][1]});
            }
        }
        
        int total=0;
        for(int i=0;i<n;i++){
            total+= bfs(mp,{stones[i][0],stones[i][1]});
        }
        return total;
        
    }
};
