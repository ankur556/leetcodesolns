class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int lh=height[l];
        int rh=height[r];
        int sol=0;
        while(l<r){
            lh=max(lh,height[l]);
            rh=max(rh,height[r]);
            if(lh>rh){sol+=(rh-height[r]);r--;}
            else{sol+=(lh-height[l]);l++;}
        }
        return sol;
    }
};