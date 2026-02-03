class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int str=0;
        bool l1=false;
        bool l2=false;
        bool l3=false;
        int end=nums.size()-1;
        while(str<nums.size()-1&&nums[str]<nums[str+1]){str++;l1=true;}
        while(end>1&&nums[end-1]<nums[end]){end--;l2=true;}
        //bool sol=true;
        if(str==nums.size()-2){return false;}
        else{
            for(int i=str;i<end;i++){if(nums[i+1]>=nums[i]){return false;}l3=true;}
            return l1&&l2&&l3;
        }
    }
};
