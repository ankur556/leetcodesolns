class Solution {
public:
    int minMoves2(vector<int>& nums) {
sort(nums.begin(),nums.end());
int avg=nums[nums.size()/2];
long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>avg){ans=ans+nums[i]-avg;}
            else{ans=ans+avg-nums[i];}
        }
        return ans;
    }
};
