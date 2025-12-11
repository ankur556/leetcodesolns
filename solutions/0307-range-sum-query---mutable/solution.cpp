class NumArray {
public:
    vector<int> a;
    vector<int> b;
    
    NumArray(vector<int>& nums) {
        for(int i:nums){a.push_back(i);}
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
            b.push_back(total);
        }
    }
    
    void update(int index, int val) {
        int diff=val-a[index];
        a[index]=val;
        for(int i=index;i<b.size();i++){
            b[i]=b[i]+diff;
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0){return b[right];}
        int sum=b[right]-b[left-1];

        
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
