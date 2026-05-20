class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z=0;int o=0;int t=0;
        for(int i:nums){
            if(i==0){z++;}
            if(i==1){o++;}
            if(i==2){t++;}
        }
        for(int i=0;i<z;i++){nums[i]=0;}
        for(int i=z;i<z+o;i++){nums[i]=1;}
        for(int i=z+o;i<nums.size();i++){nums[i]=2;}
        return;
    }
};
