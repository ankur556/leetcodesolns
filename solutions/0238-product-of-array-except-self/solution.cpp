class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1;
        vector<int> sol;
        int z=0;
        for(int i: nums){if(i==0){z++;}else{product*=i;}}
        if(z>1){
            for(int i=0;i<nums.size();i++){sol.push_back(0);}
        }
        else if(z==1){
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0){sol.push_back(product);}
                else{sol.push_back(0);}
            }
        }
        else{
            for(int i=0;i<nums.size();i++){
                sol.push_back(product/nums[i]);
            }
        }
        return sol;
    }
};
