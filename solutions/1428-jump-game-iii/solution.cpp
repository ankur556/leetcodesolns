class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        unordered_map<int,bool> vis;
        q.push(start);
        while(!q.empty()){
            int i=q.front();q.pop();
            if(i+arr[i]<arr.size()&&vis[i+arr[i]]==false){q.push(i+arr[i]);}
            if(i-arr[i]>=0&&vis[i-arr[i]]==false){q.push(i-arr[i]);}
            vis[i]=true;
            if(arr[i]==0){return true;}
        }
        return false;
    }
};
