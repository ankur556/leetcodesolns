class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> vals;
        for(int i : nums){
            if(i%k==0){
                vals[i/k]++;
            }
        }
        for(int i=1;i<=nums.size();i++){
            if(vals[i]==0){return k*i;}
        }
        return k*nums.size()+k;
    }
};