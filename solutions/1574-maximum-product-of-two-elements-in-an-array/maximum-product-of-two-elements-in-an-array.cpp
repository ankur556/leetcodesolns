class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1=-1e5;
        int max2=-1e5;
        int min1=1e5;
        int min2=1e5;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max1){max2=max1;max1=nums[i];}
            else if(nums[i]>max2){max2=nums[i];}
            if(nums[i]<min1){min2=min1;min1=nums[i];}
            else if(nums[i]<min2){min2=nums[i];}
        }
        return max((max1-1)*(max2-1),(min1-1)*(min2-1));
    }
};