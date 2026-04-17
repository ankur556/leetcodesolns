class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {

        vector<int> rev;
        for (int i = 0; i < nums.size(); i++) {
            int og=nums[i];
            while(nums[i]%10==0){
                if(nums[i]==0){break;}
                else{nums[i]=nums[i]/10;}
            }
            int r = nums[i];
            int val = 0;
            while (r > 0) {
                val = val * 10 + r % 10;
                r /= 10;
            }
            nums[i]=og;
            rev.push_back(val);
        }
        unordered_map<int,int> revt;
        //bool ex=false;
        int sol=1e9;
        for(int i=0;i<nums.size();i++){
            if(revt[nums[i]]!=0){if(i-revt[nums[i]]<sol){sol=i-revt[nums[i]];}}
            revt[rev[i]]=i+1;
        }
        if(sol==1e9){return -1;}
        return sol+1;
    }
};
