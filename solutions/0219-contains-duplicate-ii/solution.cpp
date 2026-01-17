class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>map1;
        unordered_map<int,int>map2;
        for(int i=0;i<nums.size();i++){
            if(map1[nums[i]]==0){map1[nums[i]]++;map2[nums[i]]=i;}
            else{map1[nums[i]]++;
            if(i-map2[nums[i]]<=k){return true;}
            map2[nums[i]]=i;}
        }
        return false;
    }
};
