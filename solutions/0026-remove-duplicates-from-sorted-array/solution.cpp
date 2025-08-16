class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){return 0;}
        else if(nums.size()==1){return 1;}
        else{vector<int> a;
        a.push_back(nums[0]);
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=a[a.size()-1]){
                a.push_back(nums[i]);
            }
            else{continue;}
        }
        nums=a;
            return a.size();
    }
     return nums.size();}
};
