class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    
        
        int sol=0;
        vector<int> sum;
        sum.push_back(0);
        int help=0;
        for(int i=0;i<nums.size();i++){
            help+=nums[i];
            sum.push_back(help);
        }

        for(int i=0;i<sum.size();i++){
            for(int j=i+1;j<sum.size();j++){
                if(sum[j]-sum[i]==k){sol++;}
            }
        }
        //if(k==0){return sol-1;}
        return sol;
    }
};
