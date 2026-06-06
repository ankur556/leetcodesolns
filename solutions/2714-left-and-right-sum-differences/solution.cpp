class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int cur=0;
        vector<int> left;
        vector<int> right;
        for(int i=0;i<nums.size();i++){
            left.push_back(cur);
            cur+=nums[i];
            //cout<<cur<<endl;
        }
        //vector<int>right;
        //cout<<"next:"<<endl;
        for(int i=0;i<left.size();i++){
            right.push_back(cur-left[i]-nums[i]);
            //cout<<(cur-left[i]-nums[i])<<endl;
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=abs(left[i]-right[i]);
        }
        return nums;
    }
};
