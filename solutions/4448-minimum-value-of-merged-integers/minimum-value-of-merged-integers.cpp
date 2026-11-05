class Solution {
public:
    int count(int val){
        int sol=0;
        while(val>0){val/=10;sol++;}
        return sol;
    }
    int pow(int a,int b){
        int sol=1;
        for(int i=0;i<b;i++){sol*=a;}
        return sol;
    }
    int minMergedInteger(vector<int>& nums) {
        vector<vector<int>> helper;
        vector<int> z;
        for(int i=0;i<nums.size();i+=2){
            helper.push_back({count(nums[i+1])+count(nums[i]),nums[i],nums[i+1]});
            z.push_back(nums[i+1]+ nums[i]*pow(10,count(nums[i+1])));

        }
        return *min_element(z.begin(), z.end());
        sort(z.rbegin(),z.rend());
        return helper[helper.size()-1][1]*pow(10,count(helper[helper.size()-1][2]))+helper[helper.size()-1][2];
    }
};