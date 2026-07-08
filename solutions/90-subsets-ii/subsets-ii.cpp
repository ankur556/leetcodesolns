class Solution {
public:
    void helper(vector<vector<int>> & sol,int cur,vector<int> & nums,int n,int lp,vector<int> & cv){
        if(cur>=n){sol.push_back(cv);return;}
        //if(lp==nums[cur]){}
        else{
            cv.push_back(nums[cur]);
            helper(sol,cur+1,nums,n,lp,cv);
            cv.pop_back();
            helper(sol,cur+1,nums,n,lp,cv);
            return;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> sol;
        int cur=0;
        sort(nums.begin(),nums.end());
        int lastpushed=10e3;
        vector<int> cv;
        helper(sol,cur,nums,nums.size(),lastpushed,cv);
        map<vector<int>,int> map;
        vector<vector<int>> acc;
        for(int i=0;i<sol.size();i++){
            if(map[sol[i]]==0){acc.push_back(sol[i]);map[sol[i]]=1;}
        }
        return acc;
    }
};