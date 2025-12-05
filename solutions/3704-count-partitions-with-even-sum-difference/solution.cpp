class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
      int ans=0;
      for(int i=0;i<nums.size()-1;i++){
        sum=sum-2*nums[i];
        if(sum%2==0){ans++;}
      }
      return ans;
    }
};
