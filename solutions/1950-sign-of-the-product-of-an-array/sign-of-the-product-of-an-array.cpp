class Solution {
public:
    int arraySign(vector<int>& nums) {
        int a=1;
        for(int i : nums){if(i==0){return 0;}else{
            a*=(i/(abs(i)));
        }}
        return a;
    }
};