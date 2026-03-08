class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_map<int,int> a;
        for(int i: nums){a[i]++;}
        vector<int> sol;
        for(int i: nums){if(a[i]!=0){sol.push_back(i);a[i]=0;}}
        sort(sol.begin(),sol.end());
        if(sol.size()==2){return max(sol[0],sol[1]);}
        return sol[((sol.size()-3)%(sol.size()))];

    }
};
