class Solution {
public:
    void helper(vector<vector<int>>& ans,vector<pair<int,bool>>num2,vector<int>a){
        bool all=true;
        if(a.size()==num2.size()){ans.push_back(a);return;}
        for(int i=0;i<num2.size();i++){
            vector<pair<int,bool>>num2_copy=num2;
            vector<int>a_copy=a;
            if(num2[i].second==false){num2_copy[i].second=true;a_copy.push_back(num2[i].first);helper(ans,num2_copy,a_copy);}}
        }
        
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<pair<int,bool>>num2;
        for(int i=0;i<nums.size();i++){
            num2.push_back({nums[i],false});
        }
        vector<vector<int>> ans;
        vector<int> a;
        helper(ans,num2,a);
        return ans;
    }
};
