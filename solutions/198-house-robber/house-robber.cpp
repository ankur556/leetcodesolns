class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0){return 0;}
        if(nums.size()==1){return nums[0];}
        int prev = 0;int cur = nums[0];int oldcur=0;
        for(int i=1;i<nums.size();i++){
            oldcur=cur;
            cur=max(prev+nums[i],cur);
            prev=max(prev,oldcur);
        }
        return cur;
    }
};