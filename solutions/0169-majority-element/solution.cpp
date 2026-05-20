class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> a;
        for(int i=0;i<nums.size();i++){
            a[nums[i]]++;
            if(a[nums[i]]>nums.size()/2){return nums[i];}
        }
        return nums[nums.size()-1];
    }
};
