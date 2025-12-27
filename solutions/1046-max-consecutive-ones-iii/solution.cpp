class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero=0;int ones=0;
        int max=0;
        int strt=0;int curr=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){zero++;curr++;}
            else if(nums[i]==1){ones++;curr++;}
            if(zero>k){while(nums[strt]!=0){strt++;}strt++;zero--;}
            if(max>curr-strt){continue;}
            else{max=curr-strt;}
        }
        return max;
    }
};
