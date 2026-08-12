class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> f;
        int sol=0;
        int st=0;
        for(int i=0;i<nums.size();i++){
            f[nums[i]]++;
            while(k<f[nums[i]]){
                f[nums[st]]--;st++;
            }
            if(i-st+1>sol){sol=i-st+1;}
        }
        return sol;
    }
};