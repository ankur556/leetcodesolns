class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        for(int i:nums){
            if(i%2==1){odd.push_back(i);}
            else{even.push_back(i);}
        }
        vector<int> sol;int optr=0;int eptr=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==1){sol.push_back(odd[optr]);optr++;}
            else{sol.push_back(even[eptr]);eptr++;}
        }
        return sol;
    }
};
