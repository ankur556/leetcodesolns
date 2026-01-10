class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> map;
        vector<int> sol;
        for(int i : nums){
            map[i]++;
            if(map[i]==2){sol.push_back(i);}
        }
        return sol;
    }
};
