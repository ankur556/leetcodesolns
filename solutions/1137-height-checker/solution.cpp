class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> b=heights;
        sort(b.begin(),b.end());
        int sol=0;
        for(int i=0;i<b.size();i++){
            if(heights[i]!=b[i]){sol++;}
        }
        return sol;
    }
};
