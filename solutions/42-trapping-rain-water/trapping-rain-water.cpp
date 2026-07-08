class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int lh=height[0];
        int rh=height[height.size()-1];
        int sol=0;
        while(l<r){
            lh=max(lh,height[l]);
            rh=max(rh,height[r]);
            if(lh<=rh){sol+=(lh-height[l]);l++;}
            else if(rh<lh){sol+=(rh-height[r]);r--;}
        }
        return sol;
    }
};