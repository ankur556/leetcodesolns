class Solution {
public:
    void helper(vector<vector<int>>& sol,int cp,vector<int> & cur,int n,vector<int>& nums){
        if(n==cp){sol.push_back(cur);return;}
        else{
            helper(sol,cp+1,cur,n,nums);
            cur.push_back(nums[cp]);
            helper(sol,cp+1,cur,n,nums);
            cur.pop_back();
            return;
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sol;
        int cp=0;
        vector<int> cur;
        helper( sol,cp,cur,nums.size(),nums);
        return sol;
    }
};
