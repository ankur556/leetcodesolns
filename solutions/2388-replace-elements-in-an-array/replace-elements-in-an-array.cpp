class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){map[nums[i]]=i;}
        //for(int i=0;i<operations.size();i++){map[operations[i][1]]=0;
           // map[operations[i][0]]=0;}
        for(int i=0;i<operations.size();i++){
            nums[map[operations[i][0]]]=operations[i][1];
            map[operations[i][1]]=map[operations[i][0]];
            map[operations[i][0]]=0;
        }
        return nums;
    }
};