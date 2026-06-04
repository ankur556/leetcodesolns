class Solution {
public:
    int minOperations(vector<int>& nums) {
       int z=0;
        for(int i: nums){if(i==0){z++;}}
        if(z==0){return 0;}
        //else if(z%3!=0){return -1;}
        int l=0;
        int ops=0;
        while(l<nums.size()-2){if(nums[l]==0){nums[l]^=1;nums[l+1]^=1;nums[l+2]^=1;ops++;}l++;}
        if(nums[nums.size()-1]==1&&nums[nums.size()-2]==1){return ops;}
        else{return -1;}
    }
};
