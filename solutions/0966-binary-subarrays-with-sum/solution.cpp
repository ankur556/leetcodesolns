class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum=0;
        int st=0;
        int sol=0;
        int zeros=0;
        int ogst=0;
        //int f1=0;
        int p=0;
        if(goal==0){
            for(int i=0;i<nums.size();i++){
                if(nums[i]==1){st=i+1;}
                else{sol+=(i-st+1);}
            }
            return sol;
        }
        while(nums[p]==0){
            zeros++;p++;
        }
        for(int i=p;i<nums.size();i++){
            sum+=nums[i];
            while(sum>goal){sum-=nums[st];st++;}
            if(ogst!=st){
                zeros=0;
                while(nums[st]!=1&&st<i){
                    st++;zeros++;
                }
            }
            if(sum==goal){sol+=(zeros+1);}
            ogst=st;
        }
        return sol;
    }
};
