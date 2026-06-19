class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cur=0;
        int sol=0;
        for(int i=0;i<gain.size();i++){cur+=gain[i];if(cur>sol){sol=cur;}}
        return sol;
    }
};
