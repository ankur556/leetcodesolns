class Solution {
public:
    int rob(vector<int>& nums) {
      int rob=0;
      int nrob=0;
      int lnrob=0;
      for(int i=0; i < nums.size();i++){
        lnrob=nrob;
        nrob=max(rob,nrob);
        rob=max(rob,lnrob+nums[i]);
      }  
      return rob;
    }
};