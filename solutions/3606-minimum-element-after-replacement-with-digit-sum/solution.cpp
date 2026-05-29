class Solution {
public:
    int minElement(vector<int>& nums) {
        int min=1e7;
        int cur=0;
        for(int i=0;i<nums.size();i++){
            cur=0;
            while(nums[i]>0){
                cur+=nums[i]%10;
                nums[i]/=10;
            }
            if(cur<min){min=cur;}
        }
        return min;
    }
};
