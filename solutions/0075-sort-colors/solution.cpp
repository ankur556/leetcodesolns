class Solution {
public:
    void sortColors(vector<int>& nums) {
       int no_of_0s=0; 
       int no_of_1s=0;
       int no_of_2s=0;
       for(int i=0;i<nums.size();i++)
       {if(nums[i]==0){no_of_0s++;}
       else if(nums[i]==1){no_of_1s++;}
       else if(nums[i]==2){no_of_2s++;}}
    for(int i=0;i<no_of_0s;i++){nums[i]=0;}
    for(int i=no_of_0s;i<no_of_1s+no_of_0s;i++){nums[i]=1;}
    for(int i=no_of_0s+no_of_1s;i<no_of_2s+no_of_0s+no_of_1s;i++){nums[i]=2;}
    }
};
