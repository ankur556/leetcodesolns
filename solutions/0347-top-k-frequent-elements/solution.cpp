class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i : nums){
            map[i]++;
        }
        if(k==nums.size()){return nums;}
        vector<pair<int,int>>a;
        for(int i=0;i<nums.size();i++){a.push_back({map[nums[i]],nums[i]});}
        sort(a.begin(),a.end());
        vector<int> sol;
        int i=a.size()-1;
        while(i>0&&sol.size()<k){
            if(a[i].second!=a[i-1].second){sol.push_back(a[i].second);i--;}else{i--;}
        }
        if(sol.size()==k-1){sol.push_back(a[0].second);}
    return sol;
    }
};
