class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int r=nums.size()-1;
        int l=0;
        while(l<r){
            while(r>l&&nums[r]==val){r--;}
            while(l<r&&nums[l]!=val){l++;}
            swap(nums[l],nums[r]);
        }
        int sol=0;
        for(int i : nums){if(i!=val){sol++;}}
        return sol;
    }
};