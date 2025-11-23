class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum=0;
        int smallest11=2000000;
        int smallest12=2000000;
        int smallest21=2000000;
        int smallest22=2000000;
        for(int i=0;i<nums.size();i++){
           if(nums[i]>0){ sum=sum+nums[i];}
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]%3==1&&nums[i]<smallest11){smallest12=smallest11;smallest11=nums[i];}
            else if(nums[i]%3==1&&nums[i]<smallest12){smallest12=nums[i];}
            else if(nums[i]%3==2&&nums[i]<smallest21){smallest22=smallest21;smallest21=nums[i];}
            else if(nums[i]%3==2&&nums[i]<smallest22){smallest22=nums[i];}
        }
        if(sum%3==0){return sum;}
        else if(sum%3==1){
            if(smallest21==2000000||smallest22==2000000){return sum-smallest11;}
            else{return sum-min(smallest11,smallest21+smallest22);}
        }
        else{
            if(smallest11==2000000||smallest12==2000000){return sum-smallest21;}
        
            else{return sum-min(smallest21,smallest11+smallest12);}}   
    }
};
