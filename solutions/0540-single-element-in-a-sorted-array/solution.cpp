class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int sol=0;
        for(int i: nums){sol^=i;}
        return sol;
    }
};
