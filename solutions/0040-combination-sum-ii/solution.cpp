class Solution {
public:
    void helper(vector<vector<int>>& sol,vector<int> & curr,vector<int> & candidates,int t,int i1,int r1){
        if(i1>t){return;}
        else if(i1==t){sol.push_back(curr);return;}
        else if(r1>=candidates.size()){return;}
        else{{
              curr.push_back(candidates[r1]);
            helper(sol,curr,candidates,t,i1+candidates[r1],r1+1);
            curr.pop_back();
            int next_r1=r1+1;
            while (next_r1 < candidates.size() && candidates[next_r1] == candidates[r1]) {
            next_r1++;
        }
            helper(sol,curr,candidates,t,i1,next_r1);
            return;
        }}
        }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> sol;
        vector<int> curr;
        if(candidates.size()==1){if(candidates[0]==target){sol.push_back(candidates);}return sol;}
        sort(candidates.begin(),candidates.end());
        helper(sol,curr,candidates,target,0,0);
        return sol;
    }
};
