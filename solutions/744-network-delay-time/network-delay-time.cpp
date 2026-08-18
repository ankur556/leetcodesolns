class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // times length is max 6k
        // max 6k edges
        // we can use pq
        priority_queue<vector<int>> pq;
        pq.push({0,k});
        vector<int> vis_time(n+1,-1);
        vis_time[0]=0;vis_time[k]=0;
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
            //adj[times[i][1]].push_back({times[i][0],times[i][2]});
            //cout<<times[i][0]<<" "<<times[i][1]<<endl;
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<adj[i].size();j++){
                cout<<i<<" "<<adj[i][j].first<<endl;
            }
        }
        while(!pq.empty()){
            int val=pq.top()[0];
            int idx=pq.top()[1];
            pq.pop();
            if(vis_time[idx]!=-1&&vis_time[idx]<val){continue;}
            vis_time[idx]=val;
            for(auto a : adj[idx]){
                int nid=a.first;
                int nval=a.second;
                if(vis_time[nid]==-1){vis_time[nid]=nval+val;pq.push({nval+val,nid});}
                else if(vis_time[nid]>nval+val){vis_time[nid]=nval+val;pq.push({nval+val,nid});}
            }
        }
        int un=0;
        int max=0;
        for(int i : vis_time){if(i==-1){un++;}
        max=std::max(max,i);}
        if(un!=0){return -1;}
        return max;
    }
};