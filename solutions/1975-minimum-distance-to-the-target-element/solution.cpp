class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int sol=1e9;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                if(abs(i-start)<sol){sol=abs(i-start);}
            }
        }
        return sol;
    }
};
