class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int rep=0;
        int sum=0;
        for(int i=0;i<nums.size()-1;i++){
        sum+=nums[i];
        if(nums[i]==nums[i+1]){rep=nums[i];}
        }
        sum+=nums[nums.size()-1];
        sum-=rep;
        int val=(nums.size())*(nums.size()+1)/2;
        val=val-sum;
        vector<int> ans;
        ans.push_back(rep);
        ans.push_back(val);
        return ans;
    }
};
