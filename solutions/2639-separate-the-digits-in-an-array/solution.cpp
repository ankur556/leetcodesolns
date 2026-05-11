class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> sol;
        int n=nums.size();
        for(int i=0;i<n;i++){
        vector<int> helper;
        //helper.push_back(nums[i]%10);
        while(nums[i]>0){
           helper.push_back(nums[i]%10); nums[i]/=10;
        }
        for(int i=0;i<helper.size()/2;i++){swap(helper[i],helper[helper.size()-1-i]);}
        for(int i=0;i<helper.size();i++){sol.push_back(helper[i]);}
        }
        return sol;
    }
};
