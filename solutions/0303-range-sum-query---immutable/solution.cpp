class NumArray {
public:
    vector<int> ans;
    vector<int> sol;
    NumArray(vector<int>& nums) {
        ans=nums;
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            sol.push_back(ans);ans+=nums[i];
        }
        sol.push_back(ans);
    }
    
    int sumRange(int left, int right) {
        if(left==0){
            return sol[right];
        }
        return sol[right]-sol[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
