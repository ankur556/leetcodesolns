class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int n=nums[0];
        for(int i: nums){n=gcd(n,i);}
        return n==1;
    }
};
