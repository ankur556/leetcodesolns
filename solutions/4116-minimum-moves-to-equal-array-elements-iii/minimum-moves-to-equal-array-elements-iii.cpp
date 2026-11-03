class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max=0;
        for(auto & i : nums ){
            max=std::max( max , i );
        }
        int sol=0;
        for(auto & i : nums){
            sol += (max-i);
        }
        return sol;
    }
};