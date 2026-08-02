class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> map;
        vector<int> sums;
        int sum=0;
        for(int i: nums){
           sum+=i;sums.push_back(sum);
        }
        map[0]++;
        int sol=0;
        for(int i=0;i<nums.size();i++){
            sol+=(map[sums[i]-goal]);map[sums[i]]++;
        }
        return sol;
    }
};