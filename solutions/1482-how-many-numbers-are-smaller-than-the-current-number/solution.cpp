class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> r=nums;
        sort(r.begin(),r.end());
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(r[j]==nums[i]){nums[i]=j;break;}
            }
        }
        return nums;
    }
};
