class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> pre(nums.size());
        vector<int> post(nums.size());
        int max=0;
        for(int i=0;i<nums.size();i++){
            max=std::max(max,nums[i]);
            pre[i]=max;
        }
        int min=1e9;
        for(int i=nums.size()-1;i>=0;i--){
            min=std::min(min,nums[i]);
            post[i]=min;
        }
        int sol=0;
        for(int i=0;i<nums.size();i++){
            if(pre[i]-post[i]<=k){return i;}
        }
        return -1;
    }
};