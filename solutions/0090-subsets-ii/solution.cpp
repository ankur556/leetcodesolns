class Solution {
public:
    void helper(vector<int> & nums,vector<vector<int>>& sol,vector<int> & temp,int k){
        sol.push_back(temp);
        for(int i=k;i<nums.size();i++){
            if(i==k){temp.push_back(nums[i]);helper(nums,sol,temp,i+1);temp.pop_back();}
            else if(nums[i]==nums[i-1]){continue;}
            else{temp.push_back(nums[i]);helper(nums,sol,temp,i+1);temp.pop_back();}
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>sol;
        sort(nums.begin(),nums.end());
        vector<int> temp;

        int k=0;
        helper(nums,sol,temp,k);
        return sol;
    }
};
