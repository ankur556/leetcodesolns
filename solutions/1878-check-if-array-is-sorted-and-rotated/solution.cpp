class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> b;
        if(nums.size()==1){return true;}
        for(int i:nums){b.push_back(i);}
        for(int i:nums){b.push_back(i);}
        int cur=1;
        for(int i=1;i<b.size();i++){
            
            if(b[i]>=b[i-1]){cur++;}
            else{cur=1;}
            if(cur==nums.size()){return true;}
        }
        return false;    
    }
};
