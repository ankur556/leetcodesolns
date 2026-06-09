class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long min=1e12;
        long long max=-1e12;
        for(int i:nums){if(i<min){min=i;}if(i>max){max=i;}}
        long long a=(long long)(k);
        return (max-min)*(a);
    }
};
