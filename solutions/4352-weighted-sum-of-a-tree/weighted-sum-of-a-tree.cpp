class Solution {
public:
    int h=0;
    void fh(vector<vector<int>> & adj,int  idx,int  cur_h){
        h=max(h,cur_h);
        for(int i: adj[idx]){
            fh(adj,i,cur_h+1);
        }
    }
    long long solve(vector<vector<int>>& adj,int cur_h,int & tot_h,vector<int> & w,int idx){
        long long sol=0;
        sol+=(1LL*w[idx]*(tot_h-cur_h+1));
        for(int i : adj[idx]){
            sol+=solve(adj,cur_h+1,tot_h,w,i);
        }
        return sol;
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        vector<vector<int>> adj(parent.size());
        for(int i=1;i<parent.size();i++){
            adj[parent[i]].push_back(i);
        }
        fh(adj,0,0);
        return solve(adj,0,h,nums,0);
    }
};