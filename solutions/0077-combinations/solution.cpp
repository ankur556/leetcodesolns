class Solution {
public:
    void helper(int n,int k,vector<int> & curr,vector<vector<int>> & sol,int start){
        if(k==0){sol.push_back(curr);return;}
        else if(start>n){return;}
        else {
            curr.push_back(start);
            helper(n,k-1,curr,sol,start+1);
            curr.pop_back();
            helper(n,k,curr,sol,start+1);
        }
}
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;vector<vector<int>>sol;int start=1;
        helper(n,k,curr,sol,start);
        return sol;
    }
};
