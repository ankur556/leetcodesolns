class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min=1e9;
        for(int i : nums){min=std::min(min,i);}
        int sol=0;
        for(int i : nums){sol+=(i-min);}
        return sol;
    }
};