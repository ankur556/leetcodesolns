class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int mod = 1e9 + 7;
        unordered_map<int, int> post;
        unordered_map<int, int> pre;
        for(int i=0;i<nums.size();i++) post[nums[i]] += 1;
        long long ans = 0;
        for(auto x : nums){
            post[x] -= 1;
            ans += (long long)pre[2 * x] * post[2 * x];
            pre[x] += 1;
        }
        return ans % mod;
    }
};
