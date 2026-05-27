class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sol=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();i++){
            int st=i+1;int end=nums.size()-1;
            int cur=0;
            while(st<end){
                cur=nums[i]+nums[st]+nums[end];
                if(abs(target-cur)<abs(target-sol)){sol=cur;}
                if(cur<target){st++;}
                else if(cur>target){end--;}
                else{return target;}
            }
        }
        return sol;
    }
};
