class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses,vector<int>(0));
        vector<int> ng(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ng[prerequisites[i][0]]++;
        }
        queue<int> q;
        int v=0;
        vector<int>va(numCourses,0);
        vector<int>sol;
        for(int i=0;i<numCourses;i++){if(ng[i]==0){q.push(i);}}
        while(!q.empty()){
            int a = q.front();
            q.pop();
            
            // 1. Add to solution ONLY here
            sol.push_back(a);
            
            // 2. Process neighbors
            for(int i : adj[a]){
                ng[i]--; // Reduce dependency
                
                // If dependency hits 0, push to queue so it can be processed later
                if(ng[i] == 0){
                    q.push(i);
                }
            }
        }
        if(sol.size()==numCourses){return sol;}
        vector<int>a;
        return a;
    }
};
