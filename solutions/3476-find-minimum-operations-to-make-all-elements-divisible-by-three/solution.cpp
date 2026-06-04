class Solution {
public:
    int minimumOperations(vector<int>& nums) {
      int sol=0;
        for(int i:nums){if(i%3==1){sol++;}else if(i%3==2){sol++;}}
        return sol;
    }
};
