class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses);
        for(auto a : prerequisites){
            adj[a[1]].push_back(a[0]);
            indeg[a[0]]++;
            cout<<a[1]<<adj[a[1]][0]<<endl;
            //c1
            //cout<<a[1]<<" "<<a[0]<<" "<<indeg[a[0]]<<endl;
        }
        queue<int> q;
        int vis=0;
        vector<int> v(numCourses);
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){q.push(i);vis++;}
        }
        while(!q.empty()){
            int t=q.front();
            q.pop();
            //c2
            //cout<<t<<endl;
            for(int i : adj[t]){
                //c3
                //cout<<i<<endl;
                indeg[i]--;
                //c4
                //cout<<i<<" "<<indeg[i]<<endl;
                if(indeg[i]==0){q.push(i);vis++;}
            }
        }
        cout<<vis<<endl;
        return vis==numCourses;
    }
};