class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> pre(nums.size());
        vector<int> post(nums.size());
        int max_val=0;int min_val=1e9;
        for(int i=0;i<nums.size();i++){
            max_val=std::max(max_val,nums[i]);
            pre[i]=max_val;
        }
        for(int i=nums.size()-1;i>=0;i--){
            min_val=std::min(min_val,nums[i]);
            post[i]=min_val;
        }
        for(int i=0;i<nums.size();i++){
            if(pre[i]-post[i]<=k){return i;}
        }
        return -1;
    }
};