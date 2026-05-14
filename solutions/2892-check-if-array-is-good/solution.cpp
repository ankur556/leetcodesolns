class Solution {
public:
    bool isGood(vector<int>& nums) {
        //bool sol=true;
        if(nums.size()<=1){return false;}
        unordered_map<int,int> a;
        for(int i:nums){a[i]++;}
        for(int i=1;i< nums.size();i++){
        if(i==nums.size()-1){
        if(a[i]==2){}
        else{return false;}
        }
        else{
            if(a[i]==1){}
            else{return false;}
            }
            }
        return true;
    }
};
