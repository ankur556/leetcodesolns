class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sol=0;
        int cur=0;
        for(int i: nums){
            if(i==1){cur++;}
            else{cur=0;}
            if(cur>sol){sol=cur;}
        }
        return sol;
    }
};
