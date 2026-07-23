class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      vector<vector<int>> adj(numCourses);
      vector<int> indeg(numCourses);
      vector<int> vis(numCourses);
      for(int i=0;i<prerequisites.size();i++){
        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        indeg[prerequisites[i][1]]++;
      }  
      queue<int> q;
      int cnt=0;
      for(int i=0;i<numCourses;i++){
        if(indeg[i]==0){q.push(i);vis[i]=1;cnt++;}
      }
        while(!q.empty()){
            int a=q.front();
            //cout<<a<<endl;
            q.pop();
            for(int i: adj[a]){
                //cout<<i<<endl;
                //cout<<indeg[i]<<endl;
                indeg[i]--;
                if(indeg[i]==0&&vis[i]==0){
                    vis[i]==1;q.push(i);cnt++;
                    cout<<"chala"<<endl;
                }
            }
        }
        cout<<cnt<<endl;
        return cnt==numCourses;
    }
};