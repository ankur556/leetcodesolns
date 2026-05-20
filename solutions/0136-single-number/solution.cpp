class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sol=0;
        for(int i: nums){sol^=i;}
        return sol;
    }
};
