class Solution {
public:
unordered_map<int,int> end;
unordered_map<int,int> freq;
vector<pair<int,int>> a;
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){a.push_back({nums[i],i});}
        sort(a.begin(),a.end());
        for(int i=0;i<a.size();i++){freq[a[i].first]++;end[a[i].first]=i;}
        //for(int i=0;i<nums.size();i++){freq[nums[i]]++;end[nums[i]]=i;}
    }
    
    int pick(int target) {
        if(freq[target]==1){return a[end[target]].second;}
        else{
            int rand_1=end[target]-rand()%freq[target];
            return a[rand_1].second;
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
